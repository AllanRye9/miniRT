/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:38:43 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/28 11:44:52 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathRT.h"

double	det4(const t_mat4 *matrix)
{
	return (cofactor4(matrix, 0, 0) * (*matrix)[0][0]
			+ cofactor4(matrix, 0, 1) * (*matrix)[0][1]
			+ cofactor4(matrix, 0, 2) * (*matrix)[0][2]
			+ cofactor4(matrix, 0, 3) * (*matrix)[0][3]);
}
