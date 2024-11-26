/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:40:53 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/26 13:45:50 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

void	free_textures(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->count.shapes && scene->shapes != NULL)
	{
		free_texture(&scene->shapes[i], scene->shapes[i].diffuse_tex);
		free_texture(&scene->shapes[i], scene->shapes[i].normal_tex);
	}
}

void	free_texture(t_shape *shape, t_color **texture)
{
	int	i;

	if (texture == NULL)
		return ;
	i = 0;
	while (i < shape->text_height)
	{
		free(texture[i]);
		i++;
	}
	free(texture);
}

void	free_scene(t_scene *scene)
{
	if (scene == NULL)
		return ;
	if (scene->disp != NULL && scene->disp->mlx != NULL)
	{
		mlx_destroy_image(scene->disp->mlx, scene->disp->display_img);
		mlx_destroy_image(scene->disp->mlx, scene->disp->render_img);
		mlx_destroy_image(scene->disp->mlx, scene->disp->edit_img);
		mlx_destroy_window(scene->disp->mlx, scene->disp->win);
		mlx_destroy_display(scene->disp->mlx);
		free(scene->disp->mlx);
	}
	free_textures(scene);
	if (scene->lights != NULL)
		free(scene->lights);
	if (scene->shapes != NULL)
		free(scene->shapes);
	if (scene->sem_loading != NULL)
		sem_close(scene->sem_loading);
	sem_unlink("/loading");
	free(scene);
}

t_scene	*check_elements(t_scene *scene)
{
	if (scene->count.ambient_lights > 1 || scene->count.ambient_lights == 0)
	{
		if (scene->count.ambient_lights > 1)
			printf("Error: Scene contain multiple ambient lights\n");
		else
			printf("Error: Scene contains no ambient lights\n");
		free_scene(scene);
		return (NULL);
	}
	if (scene->count.cameras > 1 || scene->count.cameras == 0)
	{
		if (scene->count.cameras > 1)
			printf("Error: Scene contains more than one camera\n");
		else
			printf("Error: Scene contains no camera\n");
		free_scene(scene);
		return (NULL);
	}
	return (scene);
}

char	*ft_strtrim_free(char *a, char *b)
{
	char	*str;

	if (!a)
		return (NULL);
	str = ft_strtrim(a, b);
	free(a);
	return (str);
}

int	is_whitespaces(char c)
{
	if (c == '\n' || c == '\f' || c == 'r' || c == '\t' || c == 32 || c == '\v')
		return (1);
	return (0);
}

int all_whitespaces(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (is_whitespaces(line[i]))
			return (1);
		i++;
	}
	return (0);
}

static int to_skipline(char **line, int fd, size_t *line_count)
{
	if (ft_strlen(*line) == 0 || all_whitespaces(*line) || ft_strncmp(*line, "//", 2) == 0 || ft_strncmp(*line, "#", 1) == 0)
	{
		free(*line);
		*line = ft_strtrim_free(get_next_line(fd), " \t\n");
		*line_count += 1;
		return (1);
	}
	return (0);
}

char **str_trimmer(char *line)
{
	char **array;
	unsigned int word_start;
	size_t word_end;
	int word_count;
	int i;

	i = 0;
	word_count = 0;
	array = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	if (!array)
		return (NULL);
	while (line[i])
	{
		while (line[i] && is_whitespaces(line[i]))
			i++;
		if (line[i] == '\0')
			break;
		word_start = i;
		while (line[i] && (!is_whitespaces(line[i])))
			i++;
		word_end = i;
		array[word_count] = ft_substr(line, word_start, word_end);
		if (array[word_count + 1] == NULL)
			return NULL;
	}
	array[word_count] = NULL;
	return array;
}

int count_array(char **arr)
{
	int no;

	no = 0;
	if (!arr)
		return NULL;
	while (arr[no])
		no++;
	return no;
}

static int atof_split(char c)
{
	char *s;
	int i;

	s = malloc(sizeof(char) * 2);
	s[0] = c;
	s[1] = '\0';
	i = ft_atoi(s);
	free(s);
	return (i);
}

static void handle_error(const char *str, bool *success)
{
	if (*str != '\0' && !ft_isdigit(*str) && !is_whitespace(*str))
		*success = 0;
}

double ft_atof(const char *str, bool *success)
{
	double i;
	int sign;
	double j;
	int k;

	i = 0;
	j = 0;
	k = 1;
	if (str[0] == '.' && str[1] == '\0')
		*success = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '.' && ft_isdigit(*str))
		i = i * 10.0 + atof_split(*str++);
	if (*str == '.')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
		j = j + atof_split(*str++) / pow(10.0, k++);
	handle_error(str, success);
	return (sign * (i + j));
}

int count_commas(char const str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ',')
			return i;
		i++;
	}
	return (i);
}

void parse_color(t_color *color, const char *str,
				 t_color_error *errs)
{
	char **rgb;
	double arr[3];
	size_t i;
	bool success;

	success = 1;
	rgb = ft_split(str, ',');
	if(!rgb || count_commas(str) || split_count(str) != 3)
	{
		errs->others = true;
		free_split_array(rgb);
		return ;
	}
	i = -1;
	while(rgb[i++])
	{
		arr[i] = atol(rgb[i], &status) / 255.0f;
		if (!is_num(rgb[i], false) || success == false)
			err.others = true;
	}
	free_split_array(rgb);
	color->r = rgb[0];
	color-g = rgb[0];
	color->r = rgb[0];
	color_range(color, errs);
}

void parse_ambient(t_scene *scene, char **s)
{
	int sucess;

	sucess = 1;
	if (count_array(s) != 3)
	{
		scene->error_flags.ambient.other = true;
		return (0);
	}
	scene->ambient.intensity = ft_atof(splitted[1], &success);
	if (success == 0 || scene->ambient.intensity < 0.0 ||
		scene->ambient.intensity > 1.0)
	{
		if (success == 0)
			scene->error_flags.ambient.intensity_range = true;
		else
			scene->error_flags.ambient.intensity_other = true;
		return (0);
	}
	parse_color(&scene->ambient.color, splitted[2],
				&scene->error_flags.ambient.color);
}

static	bool parse_line(t_scene *scene, char *line, size_t *line_num, int fd)
{
	char **trimmed;

	trimmed = str_trimmer(line);
	if (ft_strcmp(trimmed[0], "A") == 0)
		parse_ambient(scene, trimmed);
	else if (ft_strcmp(trimmed[0], "C") == 0)
		parse_camera(scene, trimmed);
	else if (ft_strcmp(trimmed[0], "L") == 0)
		parse_light(scene, trimmed);
	else if (ft_strcmp(trimmed[0], "SL") == 0)
		parse_spotLight(scene, trimmed);
	else if (is_shape(trimmed[0]))
		parse_shape(scene, trimmed);
	else
		scene->err_flag.unknow_identifier = true;
	if (find_error(&scene->err_flag))
		print_error(scene, line, *line_num, trimmed[0]);
	free(line);
	free_str_trimmer(trimmed);
	return (!find_error(&scene->err_flag));
}

t_scene *parse_scene(int fd)
{
	size_t line_count;
	t_scene *scene;
	char *line;

	line_count = 1;
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (to_skipline(&line, fd, &line_count))
			continue;
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
