/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:15:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/12 10:43:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "mathRT.h"
# include <stdbool.h>
# include "shape.h"
# include "camera.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dir;
}	t_ray;

typedef struct s_intersect
{
	double		time;
	t_shape		*shape;
	t_vector	point;
	t_vector	normal;
	t_vector	eye;
	t_vector	over_point;
	t_vector	reflect_vec;
	bool		inside;
}	t_intersection;

typedef struct s_intersections
{
	t_intersection	arr[200];
	int				count;
}	t_intersections;

t_vector	get_texture_coords(const t_shape *shape, double u, double v,
				t_vector *normal);
t_vector	sphere_normal(t_vector *normal, const t_shape *shape,
				const t_vector *itx_point);
t_vector	cube_normal(const t_shape *shape, const t_vector *itx_point);
t_vector	plane_normal(const t_shape *shape, const t_vector *itx_point);
t_vector	cone_normal(const t_shape *shape, const t_vector *itx_point);
t_vector	cylinder_normal(const t_shape *shape, const t_vector *itx_point);
t_vector	normal_map(t_vector *normal, const t_shape *shape,
				const t_vector *itx_point);
t_vector	normal_at(const t_shape *shape, const t_vector *itx_point);

#endif