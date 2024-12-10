#include "miniRT.h"

void	reflect_vector(t_vector *res, t_vector *in_vector, t_vector *normal)
{
	scale_vec(res, normal, dot_product(in_vector, normal) * 2);
	sub_vec(res, in_vector, res);
}

t_color	int_to_color(int hex_color)
{
	t_color	color;

	color.a = 0;
	color.r = ((unsigned char *)&hex_color)[2] / 255.0f;
	color.g = ((unsigned char *)&hex_color)[1] / 255.0f;
	color.b = ((unsigned char *)&hex_color)[0] / 255.0f;
	return (color);
}

unsigned int	create_mlx_color(t_color *color)
{
	return (clamp_color(color->a) << 24 | clamp_color(color->r) << 16
		| clamp_color(color->g) << 8 | clamp_color(color->b));
}
