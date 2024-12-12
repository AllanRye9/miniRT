/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/12 10:54:21 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/oallan/Desktop/minRT/include/miniRT.h"

void	drag_along_plane(t_scene *scene, t_ray *mouse_selection)
{
	t_vector	plane_orientation;
	t_vector	position_on_plane;
	double		distance_from_origin;
	double		denom;
	double		t;

	negate_vector(&plane_orientation, &scene->cam.dir);
	ray_from_cam(mouse_selection, &scene->cam,
		((double)scene->mouse.x * scene->settings.edit_w / \
		scene->settings.disp_w) + 0.5,
		((double)scene->mouse.y * scene->settings.edit_h / \
			scene->settings.disp_h) + 0.5);
	distance_from_origin = dot_product(&plane_orientation,
			&scene->shapes[scene->shape_idx].origin);
	denom = dot_product(&mouse_selection->dir, &plane_orientation);
	if (fabs(denom) < 0.00001)
		return ;
	t = -(dot_product(&mouse_selection->origin, &plane_orientation) \
		- distance_from_origin) / denom;
	ray_position(&position_on_plane, mouse_selection, t);
	scene->shapes[scene->shape_idx].origin = position_on_plane;
	if (scene->settings.collisions == true)
		collided(scene, true, 10, &scene->shapes[scene->shape_idx]);
	calc_transforms(scene);
	render_scene(scene);
}

void	rotate_along_mouse_axis(t_scene *scene)
{
	if (scene->mouse.prev_x < scene->mouse.x)
	{
		rotate_y(scene, &scene->shapes[scene->shape_idx].added_rots,
			DEG_TO_RAD * abs(scene->mouse.x - scene->mouse.prev_x) * 0.2);
	}
	else if (scene->mouse.prev_x > scene->mouse.x)
	{
		rotate_y(scene, &scene->shapes[scene->shape_idx].added_rots,
			-DEG_TO_RAD * abs(scene->mouse.x - scene->mouse.prev_x) * 0.2);
	}
	if (scene->mouse.prev_y < scene->mouse.y)
	{
		rotate_x(scene, &scene->shapes[scene->shape_idx].added_rots,
			-DEG_TO_RAD * abs(scene->mouse.y - scene->mouse.prev_y) * 0.2);
	}
	else if (scene->mouse.prev_y > scene->mouse.y)
	{
		rotate_x(scene, &scene->shapes[scene->shape_idx].added_rots,
			DEG_TO_RAD * abs(scene->mouse.y - scene->mouse.prev_y) * 0.2);
	}
}
