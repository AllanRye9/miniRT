/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:28:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/30 13:56:20 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static bool	handle_complex_collision(t_shape *shape1, t_shape *shape2,
	bool resolve, t_shape *t_s)
{
	bool	collided;

	collided = false;
	if (shape1->type == SPHERE && shape2->type == CUBE && t_s != shape2)
		collided = sphere_box_collision(shape1, shape2, false, resolve);
	else if (shape1->type == CUBE && shape2->type == SPHERE && t_s != shape2)
		collided = sphere_box_collision(shape2, shape1, true, resolve);
	else if (shape1->type == CUBE && shape2->type == PLANE)
		collided = box_plane_collision(shape1, shape2, resolve);
	else if (shape1->type == CYLINDER && shape2->type == SPHERE
		&& t_s != shape2)
		collided = cylinder_sphere_collision(shape1, shape2, resolve);
	else if (shape1->type == SPHERE && shape2->type == CYLINDER
		&& t_s != shape2)
		collided = cylinder_sphere_collision(shape2, shape1, resolve);
	else if (shape1->type == CUBE && shape2->type == CYLINDER && t_s != shape2)
		collided = box_cylinder_collision(shape1, shape2);
	else if (shape1->type == CYLINDER && shape2->type == CUBE && t_s != shape2)
		collided = box_cylinder_collision(shape2, shape1);
	return (collided);
}

bool	same_object_collision(t_shape *shape1, t_shape *shape2, bool resolve,
	t_shape *t_s)
{
	bool	collided;

	collided = false;
	if (shape1->type == SPHERE && shape2->type == SPHERE)
	{
		collided = sphere_sphere_collision(shape1, shape2);
		if (collided && resolve)
			resolve_sphere_sphere(shape1, shape2, t_s);
	}
	else if (shape1->type == CUBE && shape2->type == CUBE)
	{
		collided = box_box_collision(shape1, shape2, false);
		if (collided && resolve)
			box_box_collision_resolution(shape1, shape2, t_s);
	}
	else if (shape1->type == CYLINDER && shape2->type == CYLINDER)
		collided = cylinder_cylinder_collision(shape1, shape2);
	else if (shape1->type == CONE && shape2->type == CONE)
		collided = cone_cone_collision(shape1, shape2);
	return (collided);
}

bool	check_collision(t_shape *shape1, t_shape *shape2, bool resolve,
	t_shape *transformed_shape)
{
	bool	collided;

	collided = false;
	if (shape1->type == shape2->type)
		collided = same_object_collision(shape1, shape2, resolve,
				transformed_shape);
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
