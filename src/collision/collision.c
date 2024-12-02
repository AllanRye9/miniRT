/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:49:42 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/02 14:05:51 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	collided(t_scene *scene, bool r, int depth,
		t_shape *t)
{
	bool		collided;
	int			i;
	int			j;

	collided = false;
	calc_transform(scene);
	i = 0;
	while (i < scene->count.shapes)
	{
		j = 0;
		while (j < scene->count.shapes)
		{
			if (i == j)
				continue ;
			if (check_collision(&scene->shapes[i], &scene->shapes[j], r, t))
				collided = true;
		}
	}
	if (!r)
		return (collided);
	if (collide(scene, false, 0, NULL) == true && depth > 0)
		collide(scene, true, depth - 1, NULL);
	return (collided);
}
