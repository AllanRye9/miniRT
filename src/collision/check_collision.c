/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:28:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/03 22:55:17 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/miniRT.h"


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
	else if (shape1->type == CUBE && shape1->type == SPHERE)
		collided = sphere_box_collision(shape2, shape1, true, resolve);
	else if (shape1->type == CYLINDER && shape2->type == CYLINDER)
		collided = cylinder_cylinder_collision(shape1, shape2, false);
	else if (shape1->type == CUBE && shape2->type == CUBE)
	{
		collided = box_box_collision(shape1, shape2, false);
		if (collided && resolve)
			box_box_collision_resolution(shape1, shape2, transformed_shape);
	}
	else if (shape1->type == CONE && shape2->type == CONE)
		collided = cone_cone_collision(shape1, shape2, false);
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
