/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:02:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/07 20:20:11 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	render_scene(t_scene *scene)
{
	t_thread_data	tdata[NUM_THREADS];

	init_thread_data(tdata, scene);
	exec_thread(tdata, scene, true, thread_func);
	exec_thread(tdata, scene, false, scale_adjacent);
	mlx_put_image_to_window(scene->disp->mlx, scene->disp->win,
		scene->disp->display_img, 0, 0);
	render_shape(scene);
	if (scene->settings.light_mode == true)
	{
		project_rays_on_screen(scene);
		reflect_light(scene);
	}
	else
		render_shape_info(scene);
}
