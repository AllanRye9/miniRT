/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:59:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/26 11:40:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "miniRT.h"

typedef struct s_camera	t_camera;
struct s_camera
{
	t_vector	pos;
	t_vector	dir;
	double		fov;
	double		pixel_sz;
	double		half_w;
	double		half_h;
	t_mat4		transform;
	t_mat4		inv_trans;
	double		pi;
	double		theta;
};

typedef struct s_cam_errors	t_cam_errors;
struct s_cam_errors
{
	bool			other;
	bool			coords;
	bool			fov_other;
	bool			fov_range;
	bool			up_vector;
	t_orient_err	dir;
};

void			initialize_matrix(t_mat4 *mat, double x, double y, double z);
#endif