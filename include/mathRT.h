/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:35:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/25 22:42:52 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHRT_H
# define MATHRT_H

# define RAD_TO_DEG 57.2957795131
# define DEG_TO_RAD 0.01745329252

typedef double	t_mat4[4][4];
typedef double	t_mat3[3][3];
typedef double	t_mat2[2][2];

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector;

#endif