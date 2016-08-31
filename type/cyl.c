/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <dboudy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:45:12 by dboudy            #+#    #+#             */
/*   Updated: 2016/08/31 04:57:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "sphere.h"

static int		rt_cyl_solve(t_sphere_inter *s, t_ray *r, t_v4d *v)
{
	double			t;
	double			delta_sqrt;
	double			sa2;

	s->delta = s->b * s->b - 4.0 * s->a * s->c;
	if (s->delta < 0.0)
		return (0);
	delta_sqrt = sqrt(s->delta);
	sa2 = s->a * 2.0;
	if (s->delta == 0.0)
		t = (-s->b - delta_sqrt) / sa2;
	else
	{
		s->sol1 = (-s->b - delta_sqrt) / sa2;
		s->sol2 = (s->b - delta_sqrt) / sa2;
		t = (s->sol1 < s->sol2 ? s->sol1 : s->sol2);
		t = (t < 0.0 ? s->sol1 : s->sol2);
		if (t < 0.0)
			return (0);
	}
	if (v)
		*v = (t_v4d){r->start.x + r->dir.x * t, r->start.y + r->dir.y * t, \
			r->start.z + r->dir.z * t, 0.0};
	r->lenght = t;
	return (1);
}

int				rt_cyl_inter(t_obj *obj, t_ray *r, t_intersect *v)
{
	t_sphere_inter	s;
	double			tmp[4];
	const double	radius = (double)((t_cyl*)obj->content)->radius;
	const t_v4d		x = geo_subv4(r->start, obj->trans.w);

	tmp[0] = 1.0 / geo_dotv4(obj->rotation, obj->rotation);
	tmp[1] = geo_dotv4(r->dir, obj->rotation);
	tmp[2] = geo_dotv4(x, x);
	tmp[3] = geo_dotv4(obj->rotation, x);
	s.a = geo_dotv4(r->dir, r->dir) - (tmp[1] * tmp[1] * tmp[0]);
	s.b = 2.0 * geo_dotv4(r->dir, x) - (2 * tmp[1] * tmp[3] * tmp[0]);
	s.c = tmp[2] - (radius * radius) - ((tmp[3] * tmp[3]) * tmp[0]);
	return (rt_cyl_solve(&s, r, &v->in));
}

t_v4d			rt_cyl_normale(t_obj *obj, t_v4d *v)
{
	double		t;
	t_v4d		r;

	t = (-obj->trans.y.x * obj->trans.w.x - obj->trans.y.y * obj->trans.w.y
		- obj->trans.y.z * obj->trans.w.z + v->x * obj->trans.y.x + v->y *
		obj->trans.y.y + v->z * obj->trans.y.z) / (pow(obj->trans.y.x, 2) +
		pow(obj->trans.y.y, 2) + pow(obj->trans.y.z, 2));
	r = (t_v4d){v->x - (obj->trans.w.x + obj->trans.y.x * t),
				v->y - (obj->trans.w.y + obj->trans.y.y * t),
				v->z - (obj->trans.w.z + obj->trans.y.z * t),
				0.0};
	return (geo_normv4(r));
}
