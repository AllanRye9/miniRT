/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:48:35 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/28 21:06:08 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	calculate_orientation(t_mat4 *rot_transform, t_shape *shape)
{
	t_vector	up;
	t_vector	ax;
	double		angle;

	if (shape->orientation.x == 0 && fabs(shape->orientation.y - 1) < 0.001
		&& shape->orientation.z == 0)
		return (matrix_rotate_xaxis(rot_transform, 0));
	if (shape->orientation.x == 0 && fabs(shape->orientation.y + 1) < 0.001
		&& shape->orientation.z == 0)
		return (matrix_rotate_xaxis(rot_transform, -M_PI));
	up.x = 0;
	up.y = 0;
	up.z = 0;
	up.w = 0;
	ax.w = 0;
	normalize_vector(&up);
	normalize_vector(&shape->orientation);
	cross_product(&ax, &up, &shape->orientation);
	normalize_vector(&ax);
	angle = acos(dot_product(&shape->orientation, &up));
	axis_angle(rot_transform, &ax, angle);
}
