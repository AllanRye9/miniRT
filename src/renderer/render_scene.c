/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:02:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/09 12:53:03 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	scale_adjacent(t_thread_data *tdata)
{
	int	i_w;
	int	j_h;
	int	h;
	int	w;

	j_h = tdata->y_scale_start - 1;
	while (++j_h < tdata->y_scale_end)
	{
		i_w = -1;
		while (++i_w < tdata->scene->settings.disp_w)
		{
			w = round((i_w / (double)tdata->scene->settings.disp_w)
					* tdata->width);
			h = round((j_h / (double)tdata->scene->settings.disp_h)
					* tdata->height);
			w = min(w, tdata->width - 1);
			h = min(h, tdata->height - 1);
			*(unsigned int *)(tdata->scene->disp->display_addr
					+ (j_h * tdata->scene->settings.disp_w + i_w)
					* tdata->scene->disp->bpp) = *(unsigned int *)(tdata->addr
					+ (h * tdata->width + w) * tdata->scene->disp->bpp);
		}
	}
	return (NULL);
}

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
