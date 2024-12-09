#include "miniRT.h"

double  is_shadow(t_scene *scene, int x, t_vector *p, \
        double *p)

{
    double			distance;
	int				i;
	t_ray			ray;
	t_intersections	arr;
	t_intersection	*itx;

	sub_vec(&ray.dir, &scene->lights[i].position, i);
	distance = vec_magnitude(&ray.dir);
	scale_vec(&ray.dir, &ray.dir, 1 / distance);
	ray.origin = *i;
	if (check_spotlight(scene, i, &ray, angle) == true)
		return (true);
	i = -1;
	arr.count = 0;
	while (++i < scene->count.shapes)
		intersect(&scene->shapes[i], &ray, &arr);
	itx = hit(&arr);
	if (itx && itx->time < distance)
		return (true);
	return (false);
}