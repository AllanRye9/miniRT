#include "miniRT.h"

void	parse_light_props(t_scene *scene, t_light *light, char **splitted)
{
	bool	success;
	double	col_sum;

	success = true;
	light->type = POINT;
	parse_color(&light->color, splitted[3], &scene->error_flag.light.color);
	if (find_error(&scene->error_flag))
		return ;
	col_sum = light->color.r + light->color.g + light->color.b;
	if (light->color.r != 0 && light->color.g != 0 && light->color.b != 0)
	{
		light->color.r /= col_sum;
		light->color.g /= col_sum;
		light->color.b /= col_sum;
	}
	parse_coordinates(&light->position, splitted[1], &success);
	if (find_error(&scene->error_flag) == false && success == false)
		scene->error_flag.light.coords = true;
	light->intensity = ft_atof(splitted[2], &success);
	if (find_error(&scene->error_flag) == false && success == false)
		scene->error_flag.light.intensity_other = true;
	if (find_error(&scene->error_flag) == false
		&& (light->intensity < 0.0 || light->intensity > 1.0))
		scene->error_flag.light.intensity_range = true;
	light->intensity *= 2;
}

void	parse_light(t_scene *scene, char **splitted)
{
	if (scene->count.lights == LIGHT_MAX)
	{
		scene->error_flag.light.max_lights = true;
		return ;
	}
	if (split_count(splitted) != 4)
	{
		scene->error_flag.light.other = true;
		return ;
	}
	if (scene->lights == NULL)
		scene->lights = ft_calloc(LIGHT_MAX, sizeof(t_light));
	if (scene->lights == NULL)
		return ;
	parse_light_props(scene, &scene->lights[scene->count.lights], splitted);
	identity_matrix(&scene->lights[scene->count.lights].added_rots);
	scene->count.lights++;
}

bool	parse_ambient_props(t_scene *scene)
{
	double	col_sum;

	col_sum = scene->ambient.color.r + scene->ambient.color.g \
	+ scene->ambient.color.b;
	if (col_sum != 0)
	{
		scene->ambient.color.r /= col_sum;
		scene->ambient.color.g /= col_sum;
		scene->ambient.color.b /= col_sum;
	}
	scene->count.ambience++;
	scene->ambient.intensity *= 2;
	return (true);
}

bool	parse_ambient(t_scene *scene, char **splitted)
{
	bool	success;

	success = true;
	if (split_count(splitted) != 3)
	{
		scene->error_flag.ambient.other = true;
		return (false);
	}
	scene->ambient.intensity = ft_atof(splitted[1], &success);
	if (success == false || scene->ambient.intensity < 0.0
		|| scene->ambient.intensity > 1.0)
	{
		if (success == true)
			scene->error_flag.ambient.intensity_range = true;
		else
			scene->error_flag.ambient.intensity_other = true;
		return (false);
	}
	parse_color(&scene->ambient.color, splitted[2],
		&scene->error_flag.ambient.color);
	if (find_error(&scene->error_flag))
		return (false);
	return (parse_ambient_props(scene));
}

void	parse_camera(t_scene *scene, char **split)
{
	bool	success;

	success = true;
	if (split_count(split) != 4)
	{
		scene->error_flag.cam.other = true;
		return ;
	}
	parse_coordinates(&scene->cam.pos, split[1], &success);
	if (find_error(&scene->error_flag) == false && success == false)
		scene->error_flag.cam.coords = true;
	parse_orientation(&scene->cam.dir, split[2], &scene->error_flag.cam.dir);
	if (find_error(&scene->error_flag))
		return ;
	if (!find_error(&scene->error_flag) && fabs(scene->cam.dir.x) < 0.01
		&& fabs(scene->cam.dir.y) > 0.01 && fabs(scene->cam.dir.z) < 0.01)
		scene->error_flag.cam.up_vector = true;
	scene->cam.fov = ft_atof(split[3], &success);
	if (!find_error(&scene->error_flag)
		&& (!success || !is_num(split[3], true)))
		scene->error_flag.cam.fov_other = true;
	if (find_error(&scene->error_flag) == false
		&& (scene->cam.fov < 1 || scene->cam.fov > 180))
		scene->error_flag.cam.fov_range = true;
	scene->count.cameras++;
}
