/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:52:57 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/25 22:19:29 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	calc_shape_transform(t_shape *shape)
{
	t_mat4	scale;
	t_mat4	rot;
	t_mat4	transform;

	
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
