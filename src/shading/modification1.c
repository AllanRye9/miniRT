#include "miniRT.h"

void mult_color(t_color *res, const t_color *color, double pres)
{
	res->r = color->r * pres;
	res->g = color->g * pres;
	res->b = color->b * pres;
}

void add_colors(t_color *res , const t_color *c1, const t_color *c2)
{
	res->r = c1->r + c2->r;
	res->g = c1->g + c2->g;
	res->b = c1->b + c2->b;
}

t_color	get_ambient(t_scene *scene, t_color patter_color)
{
	t_color	ambient;

	ambient.a = 0;
	mult_color(&ambient, &patter_color,
		scene->ambient.intensity);
	blend_colors(&ambient, &ambient, &scene->ambient.color);
	return (ambient);
}

void	calculate_specular(t_vector *reflect_v, t_intersection *itx,
			t_glear *glear, t_light *light)
{
	double	reflect_dot_eye;

	reflect_dot_eye = dot_product(reflect_v, &itx->eye);
	if (reflect_dot_eye <= 0)
		ft_bzero(&glear->specular, sizeof(t_color));
	else
		mult_color(&glear->specular, &light->color,
			itx->shape->props.specular * \
			pow(reflect_dot_eye, itx->shape->props.shininess)
			* light->intensity);
}

t_color	glear(t_intersection *itx, t_scene *scene, int light_idx)
{
	t_glear			glear;
	t_color			result;
	t_color			shape_color;	
	const double	light_dist = vec_distance(&itx->point, \
			&scene->lights[light_idx].position);
	const double	attenuation = (100 * scene->lights[light_idx].intensity \
			- light_dist) / (100 * scene->lights[light_idx].intensity - 1);

	shape_color = get_shape_color(itx);
	blend_colors(&glear.effective_color, &shape_color,
		&scene->lights[light_idx].color);
	if (get_specular_and_diffuse(scene, light_idx, itx, &glear) == false)
		return (get_ambient(scene, shape_color));
	result = get_ambient(scene, shape_color);
	if (attenuation < 0)
		return (result);
	else if (attenuation > 0 && attenuation <= 1)
	{
		mult_color(&glear.diffuse, &glear.diffuse, attenuation);
		mult_color(&glear.specular, &glear.specular, attenuation);
	}
	result.r += glear.diffuse.r + glear.specular.r;
	result.g += glear.diffuse.g + glear.specular.g;
	result.b += glear.diffuse.b + glear.specular.b;
	return (result);
}
