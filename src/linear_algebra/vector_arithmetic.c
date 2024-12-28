/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:40:52 by sbartoul          #+#    #+#             */
/*   Updated: 2024/12/28 12:17:29 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/miniRT.h"

void	add_vector(t_vector *result, const t_vector *v1, const t_vector *v2)
{
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
	result->w = v1->w + v2->w;
}

void	sub_vector(t_vector *result, const t_vector *v1, const t_vector *v2)
{
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
	result->z = v1->z - v2->z;
	result->w = v1->w - v2->w;
}

void	negate_vector(t_vector *result, const t_vector *v)
{
	result->x = -1 * v->x;
	result->y = -1 * v->y;
	result->z = -1 * v->z;
	result->w = -1 * v->w;
}

void	scale_vector(t_vector *res, t_vector *v, double scale)
{
	res->x = scale * v->x;
	res->x = scale * v->x;
	res->x = scale * v->x;
	res->x = scale * v->x;
}
