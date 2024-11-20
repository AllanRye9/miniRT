/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:40:53 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/20 20:23:37 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

static int	to_skipline(char **line, int fd, size_t *line_count)
{
	if (ft_strlen(*line) == 0 || all_whitespaces(*line)
		|| ft_strncmp(*line, "//", 2) == 0 || ft_strncmp(*line, "#", 1) == 0)
	{
		free(*line);
		*line = ft_strtrim_free(get_next_line(fd), " \t\n");
		*line_count += 1;
		return (1);
	}
	return (0);
}

static bool	parse_line(t_scene *scene, char *line, size_t *line_num, int fd)
{
	char	**split_word;

	split_word = ft_split_word(line);
	if (ft_strcmp(split_word[0], "A") == 0)
		parse_ambient(scene, split_word);
	else if (ft_strcmp(split_word[0], "C") == 0)
		parse_camera(scene, split_word);
	else if (ft_strcmp(split_word[0], "L") == 0)
		parse_light(scene, split_word);
	else if (ft_strcmp(split_word[0], "SL") == 0)
		parse_spotLight(scene, split_word);
	else if (is_shape(split_word[0]))
		parse_shape(scene, split_word);
	else
		scene->error_flags.unknow_identifier = true;
	if (find_error(&scene->error_flags))
		print_error(scene, line, *line_num, split_word[0]);
	free(line);
	free_split_array(split_word);
	return (!find_error(&scene->error_flags));
}

t_scene	*parse_scene(int fd)
{
	size_t	line_count;
	t_scene	*scene;
	char	*line;

	line_count = 1;
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (to_skipline(&line, fd, &line_count))
			continue ;
		if (parse_line(scene, line, &line_count, fd) == false)
		{
			get_next_line(-1);
			free_scene(scene);
			return (NULL);
		}
		line = get_next_line(fd);
		line_count++;
	}
	return (check_elements(scene));
}
