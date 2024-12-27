/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:28:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/26 22:29:37 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	sphere_sphere_collision_resolution(t_shape *sphere1, t_shape *sphere2)
{
	t_vector	dir;
	double		dist;

	sub_vector(&dir, &sphere1->origin, &sphere2->origin);
	dist = vector_magnitude(&dir);
	if (dist < 0.001)
		return ;
	normalize_vector(&dir);
	scale_vector(&dir, &dir, dist - (sphere1->props.radius
			+ sphere2->props.radius) - 0.001);
	add_vector(&sphere2->origin, &sphere2->origin, &dir);
}

static void	resolve_sphere_sphere(t_shape *shape1, t_shape *shape2,
	t_shape *transformed_shape)
{
	if (shape2 == transformed_shape)
		sphere_sphere_collision_resolution(shape2, shape1);
	else
		sphere_sphere_collision_resolution(shape1, shape2);
}

static void	box_box_collision_resolution(t_shape *shape1, t_shape *shape2,
	t_shape *transformed_shape)
{
	if (shape2 == transformed_shape)
		box_box_collision(shape2, shape1, true);
	else
		box_box_collision(shape1, shape2, true);
}

static bool	handle_complex_collision(t_shape *shape1, t_shape *shape2,
	bool resolve, t_shape *transformed_shape)
{
	bool	collided;

	collided = false;
	if (shape1->type == SPHERE && shape2->type == CUBE)
		collided = sphere_box_collision(shape1, shape2, false, resolve);
	else if (shape1->type == CUBE && shape2->type == SPHERE)
		collided = sphere_box_collision(shape2, shape1, true, resolve);
	else if (shape1->type == CYLINDER && shape2->type == CYLINDER)
		collided = cylinder_cylinder_collision(shape1, shape2);
	else if (shape1->type == CUBE && shape2->type == CUBE)
	{
		collided = box_box_collision(shape1, shape2, false);
		if (collided && resolve)
			box_box_collision_resolution(shape1, shape2, transformed_shape);
	}
	else if (shape1->type == CONE && shape2->type == CONE)
		collided = cone_cone_collision(shape1, shape2);
	return (collided);
}

bool	check_collision(t_shape *shape1, t_shape *shape2, bool resolve,
	t_shape *transformed_shape)
{
	bool	collided;

	collided = false;
	if (shape1->type == SPHERE && shape2->type == SPHERE)
	{
		collided = sphere_sphere_collision(shape1, shape2);
		if (collided && resolve)
			resolve_sphere_sphere(shape1, shape2, transformed_shape);
	}
	else if (shape1->type == SPHERE && shape2->type == PLANE)
	{
		collided = sphere_plane_collision(shape1, shape2);
		if (collided && resolve)
			sphere_plane_collision_resolution(shape1, shape2);
	}
	else if (shape1->type == CYLINDER && shape2->type == PLANE)
	{
		collided = cylinder_plane_collision(shape1, shape2);
		if (collided && resolve)
			cylinder_plane_collision_resolution(shape1, shape2);
	}
	else
		collided = handle_complex_collision(shape1, shape2, resolve,
				transformed_shape);
	return (collided);
}
