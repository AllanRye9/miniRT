/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:02:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/27 22:22:53 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	calc_cam_transform(t_scene *scene)
{
	t_vector	from;
	t_vector	up;

	from.x = scene->cam.pos.x;
	from.y = scene->cam.pos.y;
	from.z = scene->cam.pos.z;
	from.w = 1;
	normalize_vector(&scene->cam.dir);
	up.x = 0;
	up.y = 0;
	up.z = 0;
	up.w = 0;
	view_transform(&scene->cam.transform, &from, &up, &scene->cam.dir);
	mat_inverse(&scene->cam.inv_trans, &scene->cam.transform);
}
