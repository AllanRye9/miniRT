#include "miniRT.h"

void mapping_right(double *x, double *y, t_vector *p)
{
    *x = (fmod(1 - p->z, 2.0) / 2.0);
    *y = (fmod(1 + p->y, 2.0) / 2.0);
}

void mapping_left(double *x, double *y, t_vector *p)
{
    *x = (fmod(1 + p->z, 2.0) / 2.0);
    *y = (fmod(1 + p->y, 2.0) / 2.0);
}

void mapping_up(double *x, double *y, t_vector *p)
{
    *x = (fmod(1 - p->x, 2.0) / 2.0);
    *y = (fmod(1 - p->z, 2.0) / 2.0);
}

void mapping_down(double *x, double *y, t_vector *p)
{
    *x = (fmod(1 - p->x, 2.0) / 2.0);
    *y = (fmod(1 + p->z, 2.0) / 2.0);
}

void mapping_front(double *x, double *y, t_vector *p)
{
    *x = (fmod(1 + p->X, 2.0) / 2.0);
    *y = (fmod(1 + p->y, 2.0) / 2.0);
}