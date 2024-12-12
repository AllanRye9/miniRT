/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:07:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/21 17:09:54 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	double	a;
}	t_color;

typedef struct s_glear
{
	t_color	effective_color;
	t_color	diffuse;
	t_color	specular;
	t_color	ambient;
}		t_glear;

void				calculate_specular(t_vector *reflect_v, t_intersection *itx,
					t_glear *glear, t_light *light);
t_color				ring_pattern(t_intersection *itx, t_vector point, t_color a, t_color b);
t_color				gradient_pattern(t_intersection *itx, t_vector point, t_color a,
					t_color b);
t_color				checker_pattern(t_intersection *itx, t_vector *point);
t_color				stripe_pattern(t_intersection *itx, t_vector point,
					t_color a, t_color b);
t_color				get_shape_color(t_intersection *itx);
t_color				get_texture_color(t_intersection *p);
t_color				cast_reflection_ray(t_scene *scene, t_intersection *intersection,
					int remaining, int light_idx);
t_color				coloring(int hex_color);
void 				blend_colors(t_color *res, const t_color *c1, const t_color *c2);
t_color				glear(t_intersection *itx, t_scene *scene, int light_idx);
#endif