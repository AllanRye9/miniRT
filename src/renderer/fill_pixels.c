/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:33:40 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/08 20:53:12 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/oallan/Desktop/miniRT/include/miniRT.h"


void	fill_skippedpixelh(double x, double y, t_thread_data *tdata, int th)
{
	int				i;
	int				j;
	t_intersection	arr;

	i = get_color(tdata, x - 1, y);
	i = get_color(tdata, x + 2, y);
	if (color_diff(i, j) > th)
	{
		//super_sampling function is missing created a demo for it.
		if (tdata->scene->settings.supersampling == true)
			super_sampling(tdata, &arr, x - 1, y);
		super_sampling(tdata, &arr, x, y);
		super_sampling(tdata, &arr, x + 1, y);
		if (tdata->scene->settings.supersampling == true)
			super_sampling(tdata, &arr, x + 2, y);
	}
	else
	{
		set_color(tdata, x, y, mix_color(i, j, 2.0 / 3.0));
		set_color(tdata, x + 1, y, mix_color(i, j, 2.0 / 3.0));
	}
}

void	fill_skippedpixelv(double x, double y, t_thread_data *tdata, int th)
{
	int				i;
	int				j;
	t_intersection	arr;

	i = get_color(tdata, x, y - 1);
	if (y + 2 >= tdata->y_end && y < tdata->y_end)
		super_sampling(tdata, &arr, x, y);
	if (y + 2 >= tdata->y_end && (y + 1) < tdata->y_end)
		super_sampling(tdata, &arr, x, y + 1);
	if (y + 2 >= tdata->y_end)
		return ;
	j = get_color(tdata, x, y + 2);
	if (color_difference(i, j) > th)
	{
		super_sampling(tdata, &arr, x, y - 1);
		super_sampling(tdata, &arr, x, y);
		super_sampling(tdata, &arr, x, y + 1);
		super_sampling(tdata, &arr, x, y + 2);
	}
	else
	{
		set_color(tdata, x, y, mix_color(i, j, 2.0 / 3.0));
		set_color(tdata, x, y + 1, mix_color(i, j, 1.0 / 3.0));
	}
}

void	fill_h(t_thread_data *tdata, int th)
{
	int	x;
	int	y;

	y = tdata->y_start - 1;
	while (++y < tdata->y_end)
	{
		x = 1;
		while (x < tdata->width)
		{
			if (x + 2 < tdata->width)
				fill_skippedpixelh(x, y, tdata, th);
			else
			{
				if (x < tdata->width)
					set_color(tdata, x, y, get_color(tdata, x - 1, y));
				if (x + 1 < tdata->width)
					set_color(tdata, x + 1, y, get_color(tdata, x, y));
			}
			x += 3;
		}
	}
}

void	fill_v(t_thread_data *tdata, int th)
{
	int	x;
	int	y;

	y = tdata->y_start + 1;
	while (y < tdata->y_end)
	{
		x = 1;
		while (x < tdata->width)
		{
			if (y + 2 < tdata->width)
				fill_skippedpixelv(x, y, tdata, th);
			else
			{
				if (y < tdata->height)
					set_color(tdata, x, y, get_color(tdata, x, y - 1));
				if (y + 1 < tdata->height)
					set_color(tdata, x, y + 1, get_color(tdata, x, y));
			}
			x++;
		}
		y += 3;
	}
}
