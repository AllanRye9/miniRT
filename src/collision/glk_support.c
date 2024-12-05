/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glk_support.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:17:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/05 23:41:17 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	fill_vtx(t_vector *vtx)
{
	fill_vtx0(vtx);
	fill_vtx1(vtx);
	fill_vtx2(vtx);
	fill_vtx3(vtx);
	fill_vtx4(vtx);
	fill_vtx5(vtx);
	fill_vtx6(vtx);
	fill_vtx7(vtx);
}

t_vector	cube_furthest_point(const t_vector *dir, const t_shape *box)
{
	t_vector	vtx[8];
	t_vector	transvtx[8];
	int			i;
	double		largest;
	int			largest_idx;

	fill_vtx(vtx);
	i = -1;
	while (++i < 8)
		mat_vec_mult(&transvtx[i], &box->transf, &vtx[i]);
	i = 0;
	largest = -INFINITY;
	largest_idx = 0;
	while (i < 8)
	{
		if (dot_product(dir, &transvtx[i]) > largest)
		{
			largest = dot_product(dir, &transvtx[i]);
			largest_idx = i;
		}
		i++;
	}
	return (transvtx[largest_idx]);
}
