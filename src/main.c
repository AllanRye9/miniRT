/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:54:46 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/18 21:47:49 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	read_file(int argc, char *argv[])
{
	char	*file_name;
	int		fd;

	if (argc != 2)
	{
		printf("Please provide the correct arguments\n");
		return (-1);
	}
	file_name = argv[1];
	if (ft_strncmp(&file_name[ft_strlen(file_name) - 3], ".rt", 3) != 0)
	{
		printf("Provide the file with .rt format\n");
		return (-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Not able to open the file %s\n", file_name);
		return (-1);
	}
	return (fd);
}

int	main(int argc, char *argv[])
{
	t_scene		*scene;
	t_display	dsply;
	int			fd;

	fd = read_file(argc, argv);
}
