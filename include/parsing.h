/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:13:45 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/21 20:28:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stddef.h>
# include <stdbool.h>
# include "scene.h"
# include "mathrt.h"
# include "color.h"
# include "shape.h"

typedef struct s_scene	t_scene;

typedef struct s_color_err
{
	bool	r;
	bool	g;
	bool	b;
	bool	other;
}	t_color_err;

typedef struct s_orient_err
{
	bool	x;
	bool	y;
	bool	z;
	bool	zero;
	bool	other;
}	t_orient_err;

typedef struct s_ambient_err
{
	bool		intensity_other;
	bool		intensity_range;
	bool		other;
	t_color_err	color;
}	t_ambient_err;

typedef struct s_cam_err
{
	bool			other;
	bool			coord;
	bool			fov_other;
	bool			fov_range;
	bool			up_vector;
	t_orient_err	dir;
}	t_cam_err;

typedef struct s_shape_err
{
	bool			max_shapes;
	bool			diameter_range;
	bool			diameter_other;
	bool			height_range;
	bool			height_other;
	bool			origin;
	bool			side_len_other;
	bool			side_len_range;
	bool			other;
	t_color_err		color;
	t_orient_error	orient;
}	t_shape_err;

typedef struct s_parsing_err_flag
{
	t_ambient_err	ambient;
	t_cam_errors	cam;
	t_light_errors	light;
	t_shape_errors	shape;
	bool			unkown_identifier;
	bool			setting_err;
}	t_err_flag;

#endif