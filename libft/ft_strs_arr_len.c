/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_arr_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:04:54 by oallan            #+#    #+#             */
/*   Updated: 2024/07/31 16:04:55 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/includes/libft.h"

size_t	ft_strs_arr_len(char ***str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
