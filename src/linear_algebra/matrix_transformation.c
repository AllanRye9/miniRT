/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:42:31 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/27 12:40:57 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	matrix_scaling(t_mat4 *mat, double x, double y, double z)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = x;
	(*mat)[1][1] = y;
	(*mat)[2][2] = z;
	(*mat)[3][3] = 1;
}

void	matrix_translation(t_mat4 *mat, double x, double y, double z)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = 1;
	(*mat)[0][3] = x;
	(*mat)[1][1] = 1;
	(*mat)[1][3] = y;
	(*mat)[2][2] = 1;
	(*mat)[2][3] = z;
	(*mat)[3][3] = 1;
}

void	matrix_rotate_xaxis(t_mat2 *mat, double r)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = 1;
	(*mat)[1][1] = cos(r);
	(*mat)[1][2] = -sin(r);
	(*mat)[2][1] = sin(r);
	(*mat)[2][2] = cos(r);
	(*mat)[3][3] = 1;
}

void	matrix_rotate_yaxis(t_mat2 *mat, double r)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = cos(r);
	(*mat)[0][2] = sin(r);
	(*mat)[1][1] = 1;
	(*mat)[2][0] = -sin(r);
	(*mat)[2][2] = cos(r);
	(*mat)[3][3] = 1;
}
