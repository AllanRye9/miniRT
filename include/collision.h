/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:04:23 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/05 16:22:28 by sbartoul         ###   ########.fr       */
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

typedef struct cylinder_collision_data
{
	t_vector	cylinder_normal;
	t_vector	top_cap_center;
	t_vector	bottom_cap_center;
	t_vector	cap_center;
	t_vector	resolution;
}	t_cy_collision_data;

typedef struct cylinder_plane_collision_math
{
	double		d;
	double		t;
	double		dist;
	t_ray		ray;
	t_vector	point_on_splane;
	t_vector	dir;
	t_vector	end_point;
	t_vector	plane_to_end_point;
	t_vector	resolution;
	t_vector	center_to_point;
}	t_colmath;

typedef struct cylinder_sphere_data
{
	t_vector	cylinder_to_sphere;
	t_vector	up_vector;
	double		v_dist;
	t_vector	cap_to_sphere;
	double		dist;
	double		v_cap_distance;
	double		h_cap_distance;
	t_vector	dir;
	t_vector	center_delta;
	t_vector	edge;
	t_vector	center_adjusted;
	double		edge_distance;
}	t_cy_sp_data;

typedef struct s_collision_inputs
{
	t_shape	*cylinder;
	t_shape	*sphere;
	bool	resolve;
}	t_collision_inputs;

typedef struct s_simplex
{
	t_vector	arr[4];
	int			size;
}	t_simplex;

bool		test_axis_overlap(t_box_axes *ba, t_shape *b1, t_shape *b2,
				int axis);
void		compute_center_distance(t_box_axes *ba, t_shape *b1, t_shape *b2);
void		calculate_rotation_matrices(t_box_axes *ba);
void		extract_unit_vectors(t_shape *shape, t_vector *unit_vectors);
void		initialize_box_axes(t_box_axes *ba);
bool		test_box_axes(t_shape *b1, t_shape *b2, t_vector *resolution);
bool		check_collision(t_shape *shape1, t_shape *shape2, bool resolve,
				t_shape *transformed_shape);
void		handle_secondary_plane_case(t_cy_collision_data *cy_data,
				t_shape *cylinder, t_shape *plane);
void		cylinder_plane_collision_resolution(t_shape *cylinder,
				t_shape *plane);
bool		cylinder_sphere_collision(t_shape *cylinder, t_shape *sphere,
				bool cylinder_sphere, bool resolve);
t_vector	cube_furthest_point(const t_vector *dir, const t_shape *box);
void		fill_vtx0(t_vector *vtx);
void		fill_vtx1(t_vector *vtx);
void		fill_vtx2(t_vector *vtx);
void		fill_vtx3(t_vector *vtx);
void		fill_vtx4(t_vector *vtx);
void		fill_vtx5(t_vector *vtx);
void		fill_vtx6(t_vector *vtx);
void		fill_vtx7(t_vector *vtx);

#endif
