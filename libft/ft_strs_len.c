/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:05:01 by oallan            #+#    #+#             */
/*   Updated: 2024/07/31 16:05:02 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strs_len(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
