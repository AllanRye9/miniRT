/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:10:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/29 12:07:14 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

typedef struct s_display
{
	void		*mlx;
	void		*win;
	void		*edit_img;
	char		*edit_addr;
	void		*display_img;
	void		*display_addr;
	void		*render_img;
	char		*render_addr;
	int			bpp;
	int			line_len;
	int			endian;
}		t_display;

t_intersection	*hit(t_intersections *xs);
bool			intersect(t_shape *shape, const t_ray *ray, t_intersections *xs);
bool			check_spotlight(t_scene *scene, int light_idx, t_ray *ray,
				double *angle);
t_color			reflection_color(t_intersection *itx, t_scene *scene,
				int remaining, int light_idx);
void 			cylindrical_map(double *x, double *y, t_vector *comp);
void			cubicle_mapping(double *x, double*y, t_vector *p);
void			initialize_matrix(t_mat4 *mat, double x, double y, double z);
void			mult_color(t_color *res, const t_color *color, double pres);
void			add_colors(t_color *res , const t_color *c1, const t_color *c2);
#endif