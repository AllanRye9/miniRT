#include"../include/miniRT.h"


// returns true if printed
bool	print_color_error(t_color_err *err, const char *line, int line_num,
			char *element)
{
	if (err->r)
		printf(RED_ERR);
	else if (err->g)
		printf(GREEN_ERR);
	else if (err->b)
		printf(BLUE_ERR);
	else if (err->other)
		printf(GENERIC_ERROR, element, line_num, line);
	return (ft_memchr(err, 1, sizeof(t_color_err)));
}

// // returns true if printed
bool	print_orient_error(t_orient_err *err, const char *line, int line_num,
			char *element)
{
	if (err->x)
		printf(ORIENT_X_OOR);
	else if (err->y)
		printf(ORIENT_Y_OOR);
	else if (err->z)
		printf(ORIENT_Z_OOR);
	else if (err->zero)
		printf(ORIENT_ZERO);
	else if(err->other)
		printf(GENERIC_ERROR, element, line_num, line);
	return (ft_memchr(err, 1, sizeof(t_orient_err)));
}