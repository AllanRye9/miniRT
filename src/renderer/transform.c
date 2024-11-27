/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:52:57 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/27 21:29:05 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	translate_matrix(&translate, shape->origin.x, shape->origin.y,
		shape->origin.z);
	multiply_transforms(shape, &scale, &rot, &translate);
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
		mat_vec_multlipy(&scene->lights[i].direction,
			&scene->lights[i].added_rots, &scene->lights[i].init_direction);
		i++;
	}
}
