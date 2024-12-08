/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:02:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/08 18:32:27 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	renderwith_threads(t_thread_data *tdata)
{
	t_intersection	arr;
	int				x;
	int				y;
	int				line;

	line = 0;
	y = tdata->y_start;
	while (y < tdata->y_end)
	{
		x = 0;
		while (x < tdata->width)
		{
			set_color(tdata, x, y, 0);
			x += 3;
		}
		line++;
		y += 3;
	}
	fill_h(tdata, 25);
	fill_v(tdata, 25);
	return (NULL);
}

void	render_scene(t_scene *scene)
{
	t_thread_data	tdata[NUM_THREADS];

	init_thread_data(tdata, scene);
	exec_thread(tdata, scene, true, renderwith_threads);
	exec_thread(tdata, scene, false, scale_adjacent);
	mlx_put_image_to_window(scene->disp->mlx, scene->disp->win,
		scene->disp->display_img, 0, 0);
	if (scene->settings.light_mode == true)
	{
		project_rays_on_screen(scene);
		reflect_light(scene);
	}
	else
		render_shape_info(scene);
}
