#include"../include/miniRT.h"

void	normalize_vector(t_vector *vec)
{
	scale_vector(vec, vec, 1 / vec_magnitude(vec));
	vec->w = 0;
}

void scale_vector(t_vector *res, t_vector *v, double scale)
{
        res->x = scale * res->x;
        res->x = scale * res->x;
        res->x = scale * res->x;
        res->x = scale * res->x;
}
