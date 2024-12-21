/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:35:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/07 11:21:57 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHRT_H
# define MATHRT_H

# include "miniRT.h"
# define RAD_TO_DEG 57.2957795131
# define DEG_TO_RAD 0.01745329252
# define EPSILON 0.001f

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

int		color_diff(int c1, int c2);
void	axis_angle(t_mat4 *rot_mat, const t_vector *ax, double angle);
void	matrix_multiply(t_mat4 *result, const t_mat4 *m1, const t_mat4 *m2);
void	mat_vec_mult(t_vector *result, const t_mat4 *mat, const t_vector *vec);
void	identity_matrix(t_mat4 *mat);
void	tanspose_matrix(t_mat4 *mat);
void	matrix_scaling(t_mat4 *mat, double x, double y, double z);
void	matrix_translation(t_mat4 *mat, double x, double y, double z);
void	matrix_rotate_xaxis(t_mat4 *mat, double r);
void	matrix_rotate_yaxis(t_mat2 *mat, double r);
void	matrix_rotate_axis(t_mat4 *rot_mat, const t_vector *ax, double angle);
void	add_vector(t_vector *result, const t_vector *v1, const t_vector *v2);
void	sub_vector(t_vector *result, const t_vector *v1, const t_vector *v2);
void	scale_vector(t_vector *result, const t_vector *v, double scale);
void	negate_vector(t_vector *result, const t_vector *v);
void	normalize_vector(t_vector *vect);
double	vector_magnitude(const t_vector *v);
double	dot_product(const t_vector *v1, const t_vector *v2);
void	cross_product(t_vector *result, const t_vector *v1, const t_vector *v2);
double	vec_distance(const t_vector *v1, const t_vector *v2);
void	inverse_matrix(t_mat4 *result, const t_mat4 *matrix);
double	vec_magnitude(const t_vector *vec);
#endif