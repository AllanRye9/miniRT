/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:02:42 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/10 17:08:16 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	render_loop(t_scene *scene)
{
	if (scene->settings.camera_mode == true
		&& scene->settings.edit_mode == true)
		camera_controls(scene);
	else if (scene->settings.edit_mode && !scene->settings.light_mode)
	{
		transform_object(scene);
		mouse_rotate(scene);
		mouse_move(scene);
	}
	else if (scene->settings.edit_mode && scene->settings.light_mode)
		light_controls(scene);
	if (scene->keys_held.o && scene->settings.edit_mode \
		&& !scene->look_at.trigger)
		look_at(scene, &scene->shapes[scene->shape_idx]);
	if (scene->look_at.trigger == true && scene->settings.edit_mode == true)
		look_at_animation(scene);
	if (scene->settings.edit_mode == true
		&& is_loop_hook_key(scene))
	{
		calculate_transforms(scene);
		draw_scene(scene);
	}
	return (0);
}