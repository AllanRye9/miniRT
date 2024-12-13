#include "../include/miniRT.h"

void	check_color_range(t_color *color, t_color_error *err)
{
	if (err->others == true)
		return ;
	if (color->r > 1 || color->r < 0)
		err->r = true;
	if (color->g > 1 || color->g < 0)
		err->g = true;
	if (color->b > 1 || color->b < 0)
		err->b = true;
}

void	parse_color(t_color *color, const char *str, t_color_error *errs)
{
	char	**rgb;
	double	res[3];
	size_t	i;
	bool	status;

	status = true;
	rgb = ft_split(str, ',');
	if (!rgb || count_commas(str) != 2 || split_count(rgb) != 3)
	{
		errs->others = true;
		free_2d_array(rgb);
		return ;
	}
	i = -1;
	while (rgb[++i] != NULL)
	{
		if (!is_num(rgb[i], false) || status == false)
			errs->others = true;
		res[i] = ft_atol(rgb[i], &status) / 255.0f;
	}
	free_2d_array(rgb);
	color->r = res[0];
	color->g = res[1];
	color->b = res[2];
	check_color_range(color, errs);
}

void	parse_coordinates(t_vector *position, const char *str, bool *status)
{
	double	res[3];
	char	**coords;
	size_t	i;

	coords = ft_split(str, ',');
	if (!coords || count_commas(str) != 2 || split_count(coords) != 3)
	{
		*status = false;
		free_2d_array(coords);
		return ;
	}
	i = -1;
	while (coords[++i] != NULL)
	{
		res[i] = ft_atof(coords[i], status);
		if (!is_num(coords[i], true) || *status == false)
			*status = false;
	}
	free_2d_array(coords);
	position->x = res[0];
	position->y = res[1];
	position->z = res[2];
	position->w = 1;
}

void	check_orientation_vector(t_vector *orientation, t_orient_error *err)
{
	if (err->others == true)
		return ;
	if (orientation->x < -1 || orientation->x > 1)
		err->x = true;
	if (orientation->y < -1 || orientation->y > 1)
		err->y = true;
	if (orientation->z < -1 || orientation->z > 1)
		err->z = true;
	if (vec_magnitude(orientation) == 0)
		err->zero = true;
}
