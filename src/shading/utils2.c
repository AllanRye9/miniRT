#include "miniRT.h"

void cube_map_right(double *x, double *y, t_vector *vec)
{
    *x = (fmod(1 - vec->z, 2.0) / 2.0);
    *y = (fmod(1 + vec->y, 2.0) / 2.0);
}

void cube_map_left(double *x, double *y, t_vector *vec)
{
    *x = (fmod(1 + vec->z, 2.0) / 2.0);
    *y = (fmod(1 + vec->y, 2.0) / 2.0);
}

void cube_map_up(double *x, double *y, t_vector *vec)
{
    *x = (fmod(1 - vec->z, 2.0) / 2.0);
    *y = (fmod(1 - vec->y, 2.0) / 2.0);
}

void cube_map_down(double *x, double *y, t_vector *vec)
{
    *x = (fmod(1 - vec->z, 2.0) / 2.0);
    *y = (fmod(1 + vec->y, 2.0) / 2.0);
}

void cube_map_front(double *x, double *y, t_vector *vec)
{
    *x = (fmod(1 + vec->z, 2.0) / 2.0);
    *y = (fmod(1 + vec->y, 2.0) / 2.0);
}

void cube_map_back(double *x, double *y, t_vector *vec)
{
    *x = (fmod(1 - vec->z, 2.0) / 2.0);
    *y = (fmod(1 + vec->y, 2.0) / 2.0);
}