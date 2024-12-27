/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:41:46 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/11 09:43:16 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/miniRT.h"


void	free_textures(t_shape *shape, t_color **texture)
{
	int	i;

	if (texture == NULL)
		return ;
	i = 0;
	while (i < shape->text_height)
	{
		free(texture[i]);
		i++;
	}
	free(texture);
}

void	free_textures(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->count.shapes && scene->shapes != NULL)
	{
		free_textures(&scene->shapes[i], scene->shapes[i].diffuse_tex);
		free_textures(&scene->shapes[i], scene->shapes[i].normal_tex);
	}
}
