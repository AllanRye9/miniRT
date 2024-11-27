#include "miniRT.h"

int ft_strcmp_case(const char *s1, const char *s2)
{
	while(*s1 && *s2)
	{
		if (ft_tolower(*s1) > ft_tolower(*s2))
			return (1);
		else if (ft_tolower(*s1) < ft_tolower(*s2))
			return (-1);
		else
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

bool	is_settings(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '{')
			return (true);
		if (is_space(line[i]) == false)
			return (false);
		i++;
	}
	return (false);
}

bool	is_valid_key(const char *key)
{
	if (key != NULL && (ft_strcmp(key, "reflectiveness") == 0
			|| ft_strcmp(key, "diffuse") == 0
			|| ft_strcmp(key, "specular") == 0
			|| ft_strcmp(key, "`") == 0
			|| ft_strcmp(key, "rotX") == 0
			|| ft_strcmp(key, "rotY") == 0
			|| ft_strcmp(key, "rotZ") == 0
			|| ft_strcmp(key, "scaleX") == 0
			|| ft_strcmp(key, "scaleY") == 0
			|| ft_strcmp(key, "scaleZ") == 0
			|| ft_strcmp(key, "color") == 0
			|| ft_strcmp(key, "normal_texture") == 0
			|| ft_strcmp(key, "diffuse_texture") == 0
			|| ft_strcmp(key, "tile_texture") == 0
		))
		return (true);
	return (false);
}

bool	is_valid_color(const char *color)
{
	if (ft_strcmp_case(color, "blue") == 0
		|| ft_strcmp_case(color, "red") == 0
		|| ft_strcmp_case(color, "purple") == 0
		|| ft_strcmp_case(color, "green") == 0
		|| ft_strcmp_case(color, "yellow") == 0
		|| ft_strcmp_case(color, "pink") == 0
		|| ft_strcmp_case(color, "black") == 0
		|| ft_strcmp_case(color, "gray") == 0
		|| ft_strcmp_case(color, "white") == 0
		|| ft_strcmp_case(color, "cyan") == 0
		|| ft_strcmp_case(color, "orange") == 0)
		return (true);
	printf(COLOR_SETTING_ERROR, "color", color, color);
	return (false);
}

bool	check_value(const char *key, const char *val, double min, double max)
{
	bool	status;
	double	parsed_value;

	status = true;
	if (ft_strcmp_case(key, "diffuse_texture") == 0
		|| ft_strcmp_case(key, "normal_texture") == 0
	)
	{
		if (ft_strnstr(val, ".ppm\"", ft_strlen(val)) == NULL
			|| ft_strcmp(&val[ft_strlen(val) - 5], ".ppm\"") != 0)
		{
			printf(INVALID_PROP_VALUE, key, val, val);
			printf(YELLOW"Only valid .ppm files are supported\n"RESET);
			return (false);
		}
		return (true);
	}
	if (is_num(val, true) == false)
		return (!printf(INVALID_PROP_VALUE, key, val, val));
	parsed_value = ft_atof(val, &status);
	if (status == false || parsed_value < min || parsed_value > max)
		return (!printf(INVALID_PROPERTY_RANGE, key, val, key, min, max));
	return (true);
}

bool	is_valid_val(const char *key, const char *val)
{
	double	min;
	double	max;

	if (val == NULL || ft_strlen(val) == 0)
		return (false);
	min = 0.0;
	max = 1.0;
	if (ft_strcmp(key, "shininess") == 0)
		return (check_value(key, val, 10, 400));
	if (ft_strncmp(key, "rot", 3) == 0)
		return (check_value(key, val, 0.0, 360));
	if (ft_strncmp(key, "scale", 5) == 0)
		return (check_value(key, val, 0.1, 50));
	if (ft_strcmp(key, "tile_texture") == 0)
		return (check_value(key, val, 1, 16));
	if (ft_strcmp(key, "color") == 0)
		return (is_valid_color(val));
	return (check_value(key, val, min, max));
}