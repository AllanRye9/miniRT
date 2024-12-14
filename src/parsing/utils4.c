#include "../include/miniRT.h"

long atol_helper(char *str, int i, bool *status)
{
    long tem;
    long n;

    n = 0;
    tem = 0;
    while(*str >= 0 && *str <= 9)
    {
        tem = n;
        n *= 10;
        n += str[i++] - '0';
        if (n < tem)
            return ((*status = false), 0);
        str++;
    }
    return (n);
}

void free_and_update1(char **rgb, t_color *color, t_color_error *errs)
{
	color->r = res[0];
	color->g = res[1];
	color->b = res[2];
	check_color_range(color, errs);
    free_2d_array(rgb);
}

void free_and_update2(t_vector *position, double *res, char	**coords)
{
	position->x = res[0];
	position->y = res[1];
	position->z = res[2];
	position->w = 1;
    free_2d_array(coords);
}