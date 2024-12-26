/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:39:19 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/26 12:14:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

# include "mathRT.h"
# include "miniRT.h"

typedef struct s_vector	t_vector;

typedef enum s_light_type
{
	POINT,
	SPOT
}	t_light_type;

typedef struct s_light	t_light;
typedef struct s_light
{
	t_light_type	type;
	t_vector		position;
	t_vector		direction;
	t_vector		init_direction;
	t_mat4			added_rots;
	t_color			color;
	double			intensity;
	double			theta;
}	t_light;

#endif