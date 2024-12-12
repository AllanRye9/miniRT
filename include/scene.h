/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:28:47 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/09 21:32:23 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "miniRT.h"

typedef struct s_ambient
{
	double	intensity;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	position;
	t_vector	dir;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_mat4		transform;
	t_mat4		inv_trans;
	double		phi;
	double		theta;
}	t_camera;

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

typedef struct s_el_count
{
	int		ambience;
	int		cameras;
	int		lights;
	int		shapes;
}	t_el_count;

typedef struct s_color_error
{
	bool	r;
	bool	g;
	bool	b;
	bool	others;
}	t_color_error;

typedef struct s_settings
{
	int			disp_h;
	int			disp_w;
	int			render_h;
	int			render_w;
	int			edit_h;
	int			edit_w;
	bool		camera_mode;
	bool		edit_mode;
	bool		light_mode;
	int			reflection_depth;
	double		edit_scale;
	double		render_scale;
	bool		collisions;
	bool		help_menu;
	bool		supersampling;
}	t_settings;

typedef struct s_look
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
}	t_look;

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

typedef struct s_error_flag
{
	t_ambient_err		ambient;
	t_cam_errors		cam;
	t_light_errors		light;
	t_shape_errors		shape;
	bool				unknown_identifier;
	bool				settings_err;
}	t_error_flag;

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
	t_look			look_at;
	t_mouse			mouse;
	t_error_flag	error_flag;
}	t_scene;

void 			mapping_right(double *x, double *y, t_vector *p);
void 			mapping_left(double *x, double *y, t_vector *p);
void 			mapping_up(double *x, double *y, t_vector *p);
void 			mapping_down(double *x, double *y, t_vector *p);
void 			mapping_front(double *x, double *y, t_vector *p);
#endif
