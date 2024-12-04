/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_box_axes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:31:52 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/03 22:41:05 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	resolve_resolution(t_vector *resolution, t_box_axes *ba)
{
	if (resolution)
	{
		*resolution = ba->res_axis;
		normalize_vector(resolution);
		scale_vec(resolution, resolution, ba->res_distance + 0.0001);
	}
}

bool	test_box_axes(t_shape *b1, t_shape *b2, t_vector *resolution)
{
	t_box_axes	ba;
	int			i;

	initialize_box_axes(&ba);
	extract_unit_vectors(b1, ba.b1_u);
	extract_unit_vectors(b2, ba.b2_u);
	calculate_center_distance(&ba, b1, b2);
	i = 0;
	while (i < 3)
	{
		if (!test_axis_overlap(&ba, b1, b2, 1))
			return (false);
	}
	resolve_resolution(resolution, &ba);
	return (true);
}