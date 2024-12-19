/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:08:53 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/29 18:52:40 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/oallan/Desktop/miniRT/include/miniRT.h"


void	init_display(t_display *display, t_settings *settings)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		return ;
	display->win = mlx_new_window(display->mlx, settings->disp_w,
			settings->disp_h, "miniRT");
	display->render_img = mlx_new_image(display->mlx, settings->render_w,
			settings->render_h);
	display->edit_img = mlx_new_image(display->mlx, 1920 * 3, 1080 * 3);
	display->display_img = mlx_new_image(display->mlx, settings->disp_w,
			settings->disp_h);
	display->render_addr = mlx_get_data_addr(display->render_img,
			&display->bpp, &display->line_len, &display->endian);
	display->display_addr = mlx_get_data_addr(display->display_img,
			&display->bpp, &display->line_len, &display->endian);
	display->edit_addr = mlx_get_data_addr(display->edit_img,
			&display->bpp, &display->line_len, &display->endian);
	display->bpp /= 8;
}
