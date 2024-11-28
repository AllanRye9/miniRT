/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:40:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/28 22:36:39 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "intersection.h"
# include "lights.h"

# define NUM_THREADS 16
# define REFLECTION_DEPTH 1

typedef struct s_worker
{
	int		worker_id;
	int		y_start;
	int		y_end;
	int		y_scale_start;
	int		y_scale_end;
	int		max_workers;
	int		height;
	int		width;
	char	*addr;
	t_scene	*scene;
}	t_worker;

void	calc_transform(t_scene *scene);
void	calc_cam_transform(t_scene *scene);
void	init_settings(t_settings *settings);
void	calculate_orientation(t_mat4 *rot_transform, t_shape *shape);

#endif