/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:54:46 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/26 13:34:34 by sbartoul         ###   ########.fr       */
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
	if (fd == -1)
		return (EXIT_FAILURE);
	scene = parse_scene(fd);
	if (!scene)
		return (close(fd), free_scene(scene), EXIT_FAILURE);
	close(fd);
	init_settings(&scene->settings);
	sem_unlink("/loading");
	scene->sem_loading = sem_open("/loading", O_CREAT, 0644, 0);
	init_display(&dsply, &scene->settings);
	if (dsply.mlx == NULL)
		return (close(fd), free_scene(scene), EXIT_FAILURE);
	scene->disp = &dsply;
	setup_hooks(scene);
	camera_init(&scene->cam, scene);
	scene->cam.theta = atan(scene->cam.dir.z / scene->cam.dir.x);
	scene->cam.pi = acos(scene->cam.dir.y);
	calc_transform(scene);
	draw_scene(scene);
	mlx_loop(dsply.mlx);
}
