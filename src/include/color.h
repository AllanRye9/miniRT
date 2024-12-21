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

# include "miniRT.h"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	double	a;
}	t_color;

typedef struct s_glear
{
	t_color		effective_color;
	t_color		diffuse;
	t_color		specular;
	t_color		ambient;
}	t_glear;

t_color			coloring(int hex_color);
void			blend_colors(t_color *res, const t_color *c1, const t_color *c2);
void			mult_color(t_color *res, const t_color *color, double pres);
void			add_colors(t_color *res , const t_color *c1, const t_color *c2);
void			glear_diffusion(t_color result, t_glear glear);
#endif