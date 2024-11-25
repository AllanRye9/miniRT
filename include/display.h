/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:10:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/21 17:13:41 by sbartoul         ###   ########.fr       */
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
	int			line_line;
	int			endian;
}		t_display;

#endif