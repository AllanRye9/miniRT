/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gjk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:56:40 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/04 23:14:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	sign(double num)
{
	if (num < 0)
		return (-1);
	return (1);
}

t_vector	cylinder_furthest_point(const t_vector *dir,
	const t_shape *cyl)
{
	t_vector	support_point;
	t_vector	w;
	t_vector	cyl_normal;
	t_vector	up_vector;
	t_vector	rhs;

	ft_bzero(&up_vector, sizeof(t_vector));
	up_vector.y = 1;
	mat_vec_mult(&cyl_normal, &cyl->transf, &up_vector);
	normalize_vector(&cyl_normal);
	scale_vector(&w, &cyl_normal, -dot_product(&cyl_normal, dir));
	add_vector(&w, &w, dir);
	scale_vector(&rhs, &cyl_normal, sign(dot_product(&cyl_normal, dir))
		* cyl->props.height / 2);
	add_vector(&support_point, &cyl->origin, &rhs);
	if (vector_magnitude(&w) < 0.01)
	{
		support_point.w = 1;
		return (support_point);
	}
	normalize_vector(&w);
	scale_vector(&w, &w, cyl->props.radius);
	add_vector(&support_point, &support_point, &w);
	support_point.w = 1;
	return (support_point);
}

t_vector	cone_furthest_point(const t_vector *dir, t_shape *cone)
{
	t_vector	cone_normal;
	t_vector	up_vector;
	t_vector	w;
	t_vector	support_point1;
	t_vector	support_point2;

	ft_bzero(&up_vector, sizeof(t_vector));
	up_vector.y = 1;
	mat_vec_mult(&cone_normal, &cone->transf, &up_vector);
	normalize_vector(&cone_normal);
	if (fabs(dot_product(&cone_normal, dir)) > 1)
		exit(1);
	scale_vector(&w, &cone_normal, -dot_product(&cone_normal, dir));
	add_vector(&w, &w, dir);
	normalize_vector(&w);
	scale_vector(&w, &w, cone->props.radius);
	support_point1 = cone->origin;
	add_vector(&support_point1, &support_point1, &w);
	normalize_vector(&cone_normal);
	support_point2 = cone->origin;
	scale_vector(&cone_normal, &cone_normal, -cone->props.height);
	add_vector(&support_point2, &support_point2, &cone_normal);
	if (dot_product(dir, &support_point1) > dot_product(dir, &support_point2))
		return (support_point1);
	return (support_point2);
}

t_vector	gjk_support(t_shape *shape1, t_shape *shape2, const t_vector *dir)
{
	t_vector	s1_furthest;
	t_vector	s2_furthest;
	t_vector	dir2;
	t_vector	result;

	negate_vector(&dir2, dir);
	if (shape1->type == CYLINDER)
		s1_furthest = cylinder_furthest_point(dir, shape1);
	if (shape1->type == CUBE)
		s1_furthest = cube_furthest_point(dir, shape1);
	if (shape1->type == CONE)
		s1_furthest = cone_furthest_point(dir, shape1);
	if (shape2->type == CYLINDER)
		s2_furthest = cylinder_furthest_point(&dir2, shape2);
	if (shape2->type == CUBE)
		s2_furthest = cube_furthest_point(&dir2, shape2);
	if (shape2->type == CONE)
		s2_furthest = cone_furthest_point(&dir2, shape2);
	sub_vector(&result, &s1_furthest, &s2_furthest);
	return (result);
}

bool	gjk(t_shape *s1, t_shape *s2)
{
	t_vector	dir;
	t_simplex	simplex;
	t_vector	support;
	int			i;

	simplex.size = 0;
	sub_vector(&dir, &s2->origin, &s1->origin);
	normalize_vector(&dir);
	support = gjk_support(s1, s2, &dir);
	add_to_simplex(&simplex, &support);
	negate_vector(&dir, &support);
	normalize_vector(&dir);
	i = 0;
	while (i < 50)
	{
		normalize_vector(&dir);
		support = gjk_support(s1, s2, &dir);
		if (dot_product(&support, &dir) <= 0)
			return (false);
		add_to_simplex(&simplex, &support);
		if (handle_simplex(&simplex, &dir) == true)
			return (true);
		i++;
	}
	return (false);
}
