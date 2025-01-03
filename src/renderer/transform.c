/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:52:57 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/03 14:55:08 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	multiply_transform(t_shape *shape, t_mat4 *scale, t_mat4 *rot,
		t_mat4 *translate)
{
	t_mat4	temp;

	matrix_multiply(&shape->transf, translate, &shape->added_rots);
	ft_memcpy(&temp, &shape->transf, sizeof(t_mat4));
	matrix_multiply(&shape->transf, &temp, rot);
	ft_memcpy(translate, &shape->transf, sizeof(t_mat4));
	matrix_multiply(&shape->transf, translate, scale);
	inverse_matrix(&shape->inv_transf, &shape->transf);
	if (shape->type == CONE)
	{
		matrix_translation(&temp, 0, 0.5, 0);
		matrix_multiply(&shape->inv_transf, &temp, &shape->inv_transf);
	}
	ft_memcpy(&shape->norm_transf, &shape->inv_transf, sizeof(t_mat4));
	tanspose_matrix(&shape->norm_transf);
}

void	calc_shape_transform(t_shape *shape)
{
	t_mat4	scale;
	t_mat4	rot;
	t_mat4	translate;

	identity_matrix(&shape->transf);
	identity_matrix(&scale);
	identity_matrix(&rot);
	identity_matrix(&translate);
	if (shape->type == CUBE || shape->type == SPHERE)
		matrix_scaling(&scale, shape->props.scale.x,
			shape->props.scale.y, shape->props.scale.z);
	if (shape->type == CYLINDER)
		matrix_scaling(&scale, shape->props.scale.x, 1, shape->props.scale.z);
	if (shape->type == CONE)
		matrix_scaling(&scale, shape->props.radius * 2, shape->props.height * 2,
			shape->props.radius * 2);
	if (shape->type == PLANE || shape->type == CYLINDER || shape->type == CONE)
		calculate_orientation(&rot, shape);
	matrix_translation(&translate, shape->origin.x, shape->origin.y,
		shape->origin.z);
	multiply_transform(shape, &scale, &rot, &translate);
}

void	calc_transform(t_scene *scene)
{
	int	i;

	calc_cam_transform(scene);
	i = 0;
	while (i < scene->count.shapes)
	{
		calc_shape_transform(&scene->shapes[i]);
		i++;
	}
	i = 0;
	while (i < scene->count.lights)
	{
		mat_vec_mult(&scene->lights[i].direction,
			&scene->lights[i].added_rots, &scene->lights[i].init_direction);
		i++;
	}
}
