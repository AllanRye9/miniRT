#include "../include/miniRT.h"

bool	print_sphere_error(t_shape_errors *err, const char *line, int line_num)
{
	if (print_color_error(&err->color, line, line_num, "sphere color")
		&& err->color.others)
		printf(SPHERE_SYNTAX);
	else if (err->origin)
		printf(GENERIC_ERROR, "sphere origin", line_num, line);
	else if (err->diameter_range)
		printf(POSITIVE_VALUE, "Sphere diameter", line_num, line);
	else if (err->diameter_other)
		printf(GENERIC_ERROR, "sphere diameter", line_num, line);
	else if (err->other)
		printf(GENERIC_ERROR, "sphere", line_num, line);
	if ((err->origin || err->diameter_other || err->other) && !err->color.others)
		printf(SPHERE_SYNTAX);
	return (ft_memchr(err, 1, sizeof(t_shape_errors)));
}

// returns true if printed
bool	print_cube_error(t_shape_errors *err, const char *line, int line_num)
{
	if (print_color_error(&err->color, line, line_num, "cube color")
		&& err->color.others)
		printf(CUBE_SYNTAX);
	else if (err->origin)
		printf(GENERIC_ERROR, "cube origin", line_num, line);
	else if (err->side_len_range)
		printf(POSITIVE_VALUE, "Cube side length", line_num, line);
	else if (err->side_len_other)
		printf(GENERIC_ERROR, "cube side length", line_num, line);
	else if (err->other)
		printf(GENERIC_ERROR, "cube", line_num, line);
	if ((err->origin || err->side_len_other || err->other) && !err->color.others)
		printf(CUBE_SYNTAX);
	return (ft_memchr(err, 1, sizeof(t_shape_errors)));
}

// returns true if printed
bool	print_plane_error(t_shape_errors *err, const char *line, int line_num)
{
	if (print_color_error(&err->color, line, line_num, "plane color")
		&& err->color.others)
		printf(PLANE_SYNTAX);
	else if (err->origin)
		printf(GENERIC_ERROR, "plane origin", line_num, line);
	else if (print_orient_error(&err->orient, line, line_num,
			"plane orientation")
		&& err->orient.others)
		printf(PLANE_SYNTAX);
	else if (err->other)
		printf(GENERIC_ERROR, "plane", line_num, line);
	if ((err->origin || err->other) && !err->color.others && !err->orient.others)
		printf(PLANE_SYNTAX);
	return (ft_memchr(err, 1, sizeof(t_shape_errors)));
}

bool	print_cylinder_error(t_shape_errors *err, const char *line,
		int line_num)
{
	if (print_color_error(&err->color, line, line_num, "cylinder color")
		&& err->color.others)
		printf(CYLINDER_SYNTAX);
	else if (err->origin)
		printf(GENERIC_ERROR, "cylinder origin", line_num, line);
	else if (print_orient_error(&err->orient, line, line_num,
			"cylinder orientation") && err->orient.others)
		printf(CYLINDER_SYNTAX);
	else if (err->diameter_range)
		printf(POSITIVE_VALUE, "Cylinder diameter", line_num, line);
	else if (err->diameter_other)
		printf(GENERIC_ERROR, "cylinder diameter", line_num, line);
	else if (err->height_range)
		printf(POSITIVE_VALUE, "Cylinder height", line_num, line);
	else if (err->height_other)
		printf(GENERIC_ERROR, "cylinder height", line_num, line);
	else if (err->other)
		printf(GENERIC_ERROR, "cylinder", line_num, line);
	if ((err->origin || err->diameter_other || err->height_other || err->other)
		&& !err->color.others && !err->orient.others)
		printf(CYLINDER_SYNTAX);
	return (ft_memchr(err, 1, sizeof(t_shape_errors)));
}

bool	print_cone_error(t_shape_errors *err, const char *line, int line_num)
{
	if (print_color_error(&err->color, line, line_num, "cone color")
		&& err->color.others)
		printf(CONE_SYNTAX);
	else if (err->origin)
		printf(GENERIC_ERROR, "cone origin", line_num, line);
	else if (print_orient_error(&err->orient, line, line_num,
			"cone orientation") && err->orient.others)
		printf(CONE_SYNTAX);
	else if (err->diameter_range)
		printf(POSITIVE_VALUE, "Cone diameter", line_num, line);
	else if (err->diameter_other)
		printf(GENERIC_ERROR, "cone diameter", line_num, line);
	else if (err->height_range)
		printf(POSITIVE_VALUE, "Cone height", line_num, line);
	else if (err->height_other)
		printf(GENERIC_ERROR, "cone height", line_num, line);
	else if (err->other)
		printf(GENERIC_ERROR, "cone", line_num, line);
	if ((err->origin || err->diameter_other || err->height_other || err->other)
		&& !err->color.others && !err->orient.others)
		printf(CONE_SYNTAX);
	return (ft_memchr(err, 1, sizeof(t_shape_errors)));
}