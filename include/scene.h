/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:28:47 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/25 22:35:20 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdbool.h>
# include <stdlib.h>
# include "miniRT.h"

typedef struct s_el_count
{
	int	ambient_lights;
	int	cameras;
	int	lights;
	int	shapes;
}	t_el_count;

typedef struct s_look_at
{
	t_vector	final_pos;
	t_vector	initial_orientation;
	t_vector	final_dir;
	t_vector	current_dir;
	t_vector	pos_diff;
	t_vector	dir_diff;
	bool		trigger;
	int			step_num;
	int			step_amount;
}	t_look_at;

typedef struct s_mouse
{
	bool	active;
	bool	toggle;
	int		prev_x;
	int		prev_y;
	int		x;
	int		y;
	int		key;
}	t_mouse;

typedef struct s_settings
{
	int		disp_h;
	int		disp_w;
	int		render_h;
	int		render_w;
	int		edit_h;
	int		edit_w;
	bool	camera_mode;
	bool	edit_mode;
	bool	light_mode;
	int		reflection_depth;
	double	edit_scale;
	double	render_scale;
	bool	collisions;
	bool	help_menu;
	bool	supersampling;
}	t_settings;

typedef struct s_scene
{
	t_ambient		ambient;
	t_camera		cam;
	t_light			*lights;
	t_shape			*shapes;
	t_el_count		count;
	t_display		*disp;
	t_keys			keys_held;
	t_settings		settings;
	int				shape_idx;
	int				light_idx;
	sem_t			*sem_loading;
	t_look			look_at;
	t_mouse			mouse;
	t_error_flag	err_flag;
	bool			help;
}		t_scene;

#endif
