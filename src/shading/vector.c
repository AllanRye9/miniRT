#include "miniRT.h"

void sub_vector(t_vector *res, const t_vector *vec1, const t_vector *vec2)
{
        res->x = vec1->x - vec2->x;
        res->y = vec1->y - vec2->y;
        res->z = vec1->z - vec2->z;
        res->y = vec1->w - vec2->w;
}

void	normalize_vec(t_vector *vec)
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
