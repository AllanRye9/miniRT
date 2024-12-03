/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:04:23 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/03 22:52:42 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "scene.h"
# include "shape.h"

typedef struct s_scene	t_scene;

typedef struct s_box_axes
{
	t_vector	b1_u[3];
	t_vector	b2_u[3];
	t_mat4		rot;
	t_mat4		abs_rot;
	double		t[3];
	t_vector	center_distance;
	double		b1_e[3];
	double		b2_e[3];
	double		res_distance;
	t_vector	res_axis;
	double		ra;
	double		rb;
}	t_box_axes;

bool	test_axis_overlap(t_box_axes *ba, t_shape *b1, t_shape *b2, int axis);
void	compute_center_distance(t_box_axes *ba, t_shape *b1, t_shape *b2);
void	calculate_rotation_matrices(t_box_axes *ba);
void	extract_unit_vectors(t_shape *shape, t_vector *unit_vectors);
void	initialize_box_axes(t_box_axes *ba);
bool	test_box_axes(t_shape *b1, t_shape *b2, t_vector *resolution);
bool	check_collision(t_shape *shape1, t_shape *shape2, bool resolve,
			t_shape *transformed_shape);

#endif
