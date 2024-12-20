#include "include/miniRT.h"

void	init_shape(t_shape *shape, t_scene *scene)
{
	shape->props.scale.x = shape->props.radius;
	shape->props.scale.y = shape->props.radius;
	shape->props.scale.z = shape->props.radius;
	shape->props.radius_squared = shape->props.radius * shape->props.radius;
	if (shape->type == PLANE)
		shape->props.distance_from_origin = \
			(dot_product(&shape->orientation, &shape->origin));
	shape->props.reflectiveness = 0.1;
	shape->id = scene->count.shapes;
	scene->count.shapes++;
	shape->props.diffuse = 0.9;
	shape->props.specular = 0.9;
	shape->props.shininess = 200;
	shape->props.pattern_type = NONE;
	shape->tex_tile = 1;
	identity_matrix(&shape->added_rots);
}

void	parse_sphere(t_scene *scene, t_shape *shape, char **splitted)
{
	bool	success;

	success = true;
	shape->type = SPHERE;
	if (split_count(splitted) != 4)
	{
		scene->error_flag.shape.other = true;
		return ;
	}
	parse_coordinates(&shape->origin, splitted[1], &success);
	if (!mem_error(&scene->error_flag) && success == false)
		scene->error_flag.shape.origin = true;
	shape->props.radius = ft_atof(splitted[2], &success) / 2;
	if (!mem_error(&scene->error_flag) && success == false)
		scene->error_flag.shape.diameter_other = true;
	if (!mem_error(&scene->error_flag) && shape->props.radius <= 0.0)
		scene->error_flag.shape.diameter_range = true;
	parse_color(&shape->props.color, splitted[3],
		&scene->error_flag.shape.color);
	if (mem_error(&scene->error_flag))
		return ;
}

void	parse_cube(t_scene *scene, t_shape *shape, char **splitted)
{
	bool	success;

	success = true;
	shape->type = CUBE;
	if (split_count(splitted) != 4)
	{
		scene->error_flag.shape.other = true;
		return ;
	}
	parse_coordinates(&shape->origin, splitted[1], &success);
	if (mem_error(&scene->error_flag) == false && success == false)
		scene->error_flag.shape.origin = true;
	shape->props.radius = ft_atof(splitted[2], &success);
	if (mem_error(&scene->error_flag) == false && success == false)
		scene->error_flag.shape.side_len_other = true;
	if (mem_error(&scene->error_flag) == false && shape->props.radius <= 0.0)
		scene->error_flag.shape.side_len_range = true;
	parse_color(&shape->props.color, splitted[3],
		&scene->error_flag.shape.color);
	if (mem_error(&scene->error_flag) == true)
		return ;
}

void	parse_plane(t_scene *scene, t_shape *shape, char **splitted)
{
	bool	success;

	success = true;
	shape->type = PLANE;
	if (split_count(splitted) != 4)
	{
		scene->error_flag.shape.other = true;
		return ;
	}
	parse_coordinates(&shape->origin, splitted[1], &success);
	if (mem_error(&scene->error_flag) == false && success == false)
		scene->error_flag.shape.origin = true;
	parse_orientation(&shape->orientation, splitted[2],
		&scene->error_flag.shape.orient);
	if (mem_error(&scene->error_flag) == true)
		return ;
	parse_color(&shape->props.color, splitted[3],
		&scene->error_flag.shape.color);
	if (mem_error(&scene->error_flag) == true)
		return ;
}

bool	is_shape(const char *identifier)
{
	return (ft_strcmp(identifier, "sp") == 0
		|| ft_strcmp(identifier, "pl") == 0
		|| ft_strcmp(identifier, "cy") == 0
		|| ft_strcmp(identifier, "cu") == 0
		|| ft_strcmp(identifier, "co") == 0);
}