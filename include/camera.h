/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:59:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/21 17:04:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "mathRT.h"

typedef struct s_camera
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
}		t_camera;

#endif