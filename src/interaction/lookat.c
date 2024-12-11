/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:15:00 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/11 11:16:35 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	look_at(t_scene *scene, t_shape *shape)
{
	t_vector	cam_to_object;

	sub_vector(&cam_to_object, &shape->origin, &scene->cam.pos);
	negate_vector(&cam_to_object, &cam_to_object);
	if (vector_magnitude(&cam_to_object) < 2)
		return ;
	if (shape->type == SPHERE)
		sphere_lookat_pos(&cam_to_object, &scene->look_at, shape);
	if (shape->type == CUBE)
		cube_lookat_pos(&cam_to_object, &scene->look_at, shape);
	if (shape->type == CYLINDER || shape->type == CONE)
		cylinder_cone_lookat_pos(&cam_to_object, &scene->look_at, shape);
	sub_vec(&scene->look_at.final_dir, &shape->origin,
		&scene->look_at.final_pos);
	normalize_vector(&scene->look_at.final_dir);
	scene->look_at.current_dir = scene->cam.dir;
	scene->look_at.initial_orientation = scene->cam.dir;
	scene->look_at.step_num = 0;
	sub_vector(&scene->look_at.pos_diff, &scene->look_at.final_pos,
		&scene->cam.pos);
	sub_vector(&scene->look_at.dir_diff, &scene->look_at.final_dir,
		&scene->cam.dir);
	scene->look_at.step_amount = (vec_magnitude(&scene->look_at.pos_diff) + \
		vec_magnitude(&scene->look_at.dir_diff)) + 2;
	scene->look_at.trigger = true;
}
