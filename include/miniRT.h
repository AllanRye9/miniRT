/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:55:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/29 20:40:38 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

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
# include "edit_mode.h"

typedef struct s_vector
{
    double x;
    double y;
    double z;
    double w;
} t_vector;
# include "../mlx/mlx.h"
# include "mathRT.h"
# include "color.h"
# include "display.h"
# include "shape.h"
# include "camera.h"
# include "intersection.h"
# include "lights.h"
# include "scene.h"
# include "render.h"
# include "parsing.h"
# include "utils.h"
# include "collision.h"
# include "shape.h"
# include "macro.h"
# define EPSILON 0.001f

#endif