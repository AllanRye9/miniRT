/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:40:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/21 20:50:30 by sbartoul         ###   ########.fr       */
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

#endif