/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:55:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/12 12:31:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include "libft.h"
# include <stdio.h>
# include "display.h"
# include "mode.h"
# include "color.h"
# include "lights.h"
# include "shape.h"
# include "scene.h"
# include "parsing.h"
# include "parsing2.h"
# include "interactions.h"
# include "../mlx/mlx.h"
# include "mathRT.h"
# include "display.h"
# include "camera.h"
# include "intersection.h"
# include "render.h"
# include "math_utils.h"
# include "collision.h"
# include "macro.h"
# define EPSILON 0.001f

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector;

#endif