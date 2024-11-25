/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:55:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/25 19:50:44 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include "libft.h"
# include <stdio.h>
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
# include "collisions.h"
# define EPSILON 0.001f

#endif