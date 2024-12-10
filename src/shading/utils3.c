#include "miniRT.h"

double	vec_magnitude(const t_vector *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y \
			+ vec->z * vec->z));
}

bool	is_shadow(t_scene *scene, int light_idx, t_vector *itx_point,
			double *angle)
{
	double			distance;
	int				i;
	t_ray			ray;
	t_intersections	arr;
	t_intersection	*itx;

	sub_vec(&ray.dir, &scene->lights[light_idx].position, itx_point);
	distance = vec_magnitude(&ray.dir);
	scale_vec(&ray.dir, &ray.dir, 1 / distance);
	ray.origin = *itx_point;
	if (check_spotlight(scene, light_idx, &ray, angle) == true)
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