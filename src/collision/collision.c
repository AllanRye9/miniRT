/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:49:42 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/07 18:52:24 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/oallan/Desktop/minRT/include/miniRT.h"

bool	collided(t_scene *scene, bool r, int depth,
		t_shape *t)
{
	bool		did_collide;
	int			i;
	int			j;

	did_collide = false;
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
				did_collide = true;
		}
	}
	if (!r)
		return (did_collide);
	if (collided(scene, false, 0, NULL) == true && depth > 0)
		collided(scene, true, depth - 1, NULL);
	return (did_collide);
}
