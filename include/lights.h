/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:39:19 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/21 12:37:23 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
#define LIGHTS_H

# include "mathRT.h"

typedef struct s_light
{
	t_light 	type;
	t_vector 	position;
	t_vector 	dirctn;
	t_vector 	init_dirctn;
	t_mat4 		added_rots;
	t_color 	color;
	double 		intensity;
	double 		theta;
} t_light;

typedef enum s_light_type
{
	POINT,
	SPOT
} t_light_type;

#endif