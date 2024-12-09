#include "miniRT.h"

void mat4_multiply(t_vector *res, const t_mat4 *mat,
    const t_vector *vec)
{
    res->x = vec->x * (*mat)[0][0] + vec->y * (*mat)[0][1] \
            + vec->z * (*mat)[0][2] + vec->w * (*mat)[0][3];
    res->y = vec->x * (*mat)[1][0] + vec->y * (*mat)[1][1] \
            + vec->z * (*mat)[1][2] + vec->w * (*mat)[1][3];
    res->z = vec->x * (*mat)[2][0] + vec->y * (*mat)[2][1] \
            + vec->z * (*mat)[2][2] + vec->w * (*mat)[2][3];
    res->w = vec->x * (*mat)[3][0] + vec->y * (*mat)[3][1] \
            + vec->z * (*mat)[3][2] + vec->w * (*mat)[3][3];
}

void cylindrical_map(double *x, double *y, t_vector *comp)
{
        double res;

        res = atan2(comp->x, comp->z);
        *x = 1 - (res / (2 * M_PI) + 0.5);
        *y = comp->y - floor(comp->y);
}

void sub_vec(t_vector *res, const t_vector *vec1, const t_vector *vec2)
{
        res->x = vec1->x - vec2->x;
        res->y = vec1->y - vec2->y;
        res->z = vec1->z - vec2->z;
        res->y = vec1->w - vec2->w;
}

void	normalize_vec(t_vector *vec)
{
	scale_vec(vec, vec, 1 / vec_magnitude(vec));
	vec->w = 0;
}

void scale_vec(t_vector *res, t_vector *v, double scale)
{
        res->x = scale * res->x;
        res->x = scale * res->x;
        res->x = scale * res->x;
        res->x = scale * res->x;

}