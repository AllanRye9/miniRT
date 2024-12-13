#include "../include/miniRT.h"

void	parse_orientation(t_vector *orientation, const char *str,
			t_orient_error *err)
{
	double	res[3];
	char	**xyz;
	size_t	i;
	bool	status;

	status = true;
	xyz = ft_split(str, ',');
	if (xyz == NULL || count_commas(str) != 2 || split_count(xyz) != 3)
	{
		free_2d_array(xyz);
		err->others = true;
		return ;
	}
	i = -1;
	while (xyz[++i] != NULL)
	{
		res[i] = ft_atof(xyz[i], &status);
		if (status == false || !is_num(xyz[i], true))
			err->others = true;
	}
	free_2d_array(xyz);
	orientation->x = res[0];
	orientation->y = res[1];
	orientation->z = res[2];
	check_orientation_vector(orientation, err);
}