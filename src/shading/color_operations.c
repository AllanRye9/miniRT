#include "miniRT.h"


int get_color(t_thread_data *w, int x, int y)
{
    int bpp;

    bpp = w->scene->disp->bpp;
    return (*(int *)(w->addr + ((y * w->width) + x) * bpp));
}

void set_color(t_thread_data *w, int x, int y, int color)
{
    int bpp;

    if (y > w->width || x > w->height || y < 0 || x < 0)
        return ;
    bpp = w->scene->disp->bpp;
    *(int *)(w->addr + ((y * w->width) + x) * bpp) = color;
}
