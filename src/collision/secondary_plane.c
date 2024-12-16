/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:22:38 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/04 12:17:09 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


bool	compute_ray_plane_intersection(t_colmath *col_math,
	t_cy_collision_data *cy_data, t_shape *plane)
{
	double	denom;

	col_math->d = -(dot_product(&cy_data->cylinder_normal,
				&cy_data->cap_center));
	col_math->ray.origin = plane->origin;
	negate_vec(&col_math->ray.dir, &plane->orientation);
	normalize_vec(&col_math->ray.dir);
	denom = dot_product(&cy_data->cylinder_normal,
			&col_math->ray.dir);
	if (fabs(denom) < 0.001)
		return (false);
	col_math->t = -(dot_product(&cy_data->cylinder_normal,
				&col_math->ray.origin) + col_math->d) / denom;
	ray_position(&col_math->point_on_splane, &col_math->ray, col_math->t);
	return (true);
}

void	resolve_non_parallel_case(t_colmath *col_math,
	t_cy_collision_data *cy_data, t_shape *cylinder, t_shape *plane)
{
	sub_vec(&col_math->dir, &col_math->point_on_splane, &cy_data->cap_center);
	if (vec_magnitude(&col_math->dir) < 0.001)
		return ;
	normalize_vec(&col_math->dir);
	scale_vec(&col_math->dir, &col_math->dir, cylinder->props.radius + 0.01);
	add_vec(&col_math->end_point, &cy_data->cap_center, &col_math->dir);
	sub_vec(&col_math->plane_to_end_point, &col_math->end_point,
		&plane->origin);
	col_math->dist = fabs(dot_product(&col_math->plane_to_end_point,
				&plane->orientation));
	col_math->resolution = plane->orientation;
	scale_vec(&col_math->resolution, &col_math->resolution,
		col_math->dist + 0.001);
	add_vec(&cylinder->origin, &cylinder->origin, &col_math->resolution);
}

void	resolve_parallel_case(t_colmath *col_math, t_cy_collision_data *cy_data,
	t_shape *cylinder, t_shape *plane)
{
	sub_vec(&col_math->center_to_point, &plane->origin, &cylinder->origin);
	col_math->dist = fabs(dot_product(&col_math->center_to_point,
				&plane->orientation));
	col_math->resolution = plane->orientation;
	scale_vec(&col_math->resolution, &col_math->resolution,
		cylinder->props.radius - col_math->dist + 0.001);
	add_vec(&cylinder->origin, &cylinder->origin, &col_math->resolution);
}

void	handle_secondary_plane_case(t_cy_collision_data *cy_data,
	t_shape *cylinder, t_shape *plane)
{
	t_colmath	col_math;

	if (compute_ray_plane_intersection(&col_math, cy_data, plane))
		resolve_non_parallel_case(&col_math, cy_data, cylinder, plane);
	else
		resolve_parallel_case(&col_math, cy_data, cylinder, plane);
}
