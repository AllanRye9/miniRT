/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:15:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/25 18:05:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <stdbool.h>
# include "miniRT.h"
# include "render.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dir;
}	t_ray;

typedef struct s_intersect
{
	double		time;
	t_shape		*shape;
	t_vector	point;
	t_vector	normal;
	t_vector	eye;
	t_vector	over_point;
	t_vector	reflect_vec;
	bool		inside;
}	t_intersection;

typedef struct s_intersections
{
	t_intersection	arr[200];
	int				count;
}	t_intersections;

void			calculate_specular(t_vector *reflect_v, t_intersection *itx,
				t_glear *glear, t_light *light);
t_color			ring_pattern(t_intersection *itx, t_vector point, t_color a, t_color b);
t_color			gradient_pattern(t_intersection *itx, t_vector point, t_color a,
				t_color b);
t_color			checker_pattern(t_intersection *itx, t_vector *point);
t_color			stripe_pattern(t_intersection *itx, t_vector point,
				t_color a, t_color b);
t_color			get_shape_color(t_intersection *itx);
t_color			get_texture_color(t_intersection *p);
t_color			cast_reflection_ray(t_scene *scene, t_intersection *intersection,
				int remaining, int light_idx);
t_color			glear(t_intersection *itx, t_scene *scene, int light_idx);
t_color			reflection_color(t_intersection *itx, t_scene *scene,
				int remaining, int light_idx);
bool			intersect(t_shape *shape, const t_ray *ray, t_intersections *xs);
t_intersection	*hit(t_intersections *xs);
t_vector		get_texture_coords(const t_shape *shape, double u, double v, t_vector *normal);
t_vector		sphere_normal(t_vector *normal, const t_shape *shape, const t_vector *itx_point); 
t_vector		cube_normal(const t_shape *shape, const t_vector *itx_point);
t_vector		plane_normal(const t_shape *shape, const t_vector *itx_point);
t_vector		cone_normal(const t_shape *shape, const t_vector *itx_point);
t_vector		cylinder_normal(const t_shape *shape, const t_vector *itx_point);
t_vector		normal_map(t_vector *normal, const t_shape *shape, const t_vector *itx_point);
t_vector		normal_at(const t_shape *shape, const t_vector *itx_point);
void			prepare_computations(t_intersection *intersection,
				t_ray *ray);
bool			get_specular_and_diffuse(t_scene *scene, int light_idx,
				t_intersection *itx, t_glear *phong);
void			super_sampling(t_thread_data *tdata, t_intersection	*arr, 
				int i, double x);
void			cylindrical_map(double *u, double *v, t_vector *point);
void			spherical_map(double *u, double *v, t_vector *point);
#endif