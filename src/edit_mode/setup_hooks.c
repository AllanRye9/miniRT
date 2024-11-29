/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:33:51 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/29 20:42:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	setup_hooks(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->count.shapes && scene->shapes[i].type == PLANE)
		i++;
	if (i == scene->count.shapes && scene->count.shapes > 0)
	{
		scene->shapes[0].props.highlighted = false;
		scene->shape_idx = -1;
	}
	else if (scene->shapes[i].type != PLANE && scene->count.shapes > 0)
	{
		scene->shapes[i].props.highlighted = true;
		scene->shape_idx = i;
	}
	mlx_hook(scene->disp->win, 2, (1L << 0), key_press, scene);
	mlx_hook(scene->disp->win, 3, (1L << 1), key_release, scene);
	mlx_hook(scene->disp->win, 4, (1L << 2), mouse_down, scene);
	mlx_hook(scene->disp->win, 5, (1L << 3), mouse_up, scene);
	mlx_hook(scene->disp->win, 17, 0, close_window, scene);
	mlx_loop_hook(scene->disp->mlx, render_loop, scene);
}