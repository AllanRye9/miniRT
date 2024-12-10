#include "miniRT.h"

t_color texture_mapping(t_intersection *p, double h, double w)
{
    if (p->shape->tex_tile != 0)
    {
        h = (int)floor(h * ((p->shape->text_height - 1) * (p->shape->tex_tile))) \
        % (p->shape->text_height);
        w = (int)floor(w * ((p->shape->tex_width - 1) * (p->shape->tex_tile))) \
        % (p->shape->tex_width);
    }
    else
    {
        h = (int)floor(p->shape->text_height - 1);
        w = (int)floor(p->shape->tex_width - 1);
    }
    if(h >= p->shape->text_height || w >= p->shape->tex_width)
        return (p->shape->props.color);
    return (p->shape->diffuse_texs[(int)h][(int)w]);
}

t_color get_texture_color(t_intersection *p)
{
    t_vector    comp;
    double      x;
    double      y;

    mat4_multiply(&comp, &p->shape->inv_transf, &p->point);
    if (p->shape->type == CONE || p->shape->type == CYLINDER)
    {
        comp.y /= p->shape->props.height;
        comp.y -= 0.5;
        cylindrical_map(&x, &y, &comp);
    }
}

bool	get_specular_and_diffuse(t_scene *scene, int light_x,
	t_intersection *p, t_phong *value)
{
        double   dot;
        double   s_angle;
        t_vector light_v;
        t_vector reflect_v;

        s_angle = 0;
        sub_vec(&light_v, &scene->lights[light_x].position, 
                p->over_point);
        normalize_vec(&light_v);
        p->normal.w = 0;
        dot = dot_product(&light_v, &p->normal);
        if (dot < 0 || is_shadow(scene, light_x, &p->over_point \
            &s_angle))
            return (false);
        
}