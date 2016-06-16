/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 21:03:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/16 16:16:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		check(float *box, float start, float dir, double *tb)
{
	double	tmin;
	double	tmax;

	tmin = (double)(box[0] - start);
	tmax = (double)(box[1] - start);
	if (dir != 0.0f)
	{
		tmin = tmin / (double)dir;
		tmax = tmax / (double)dir;
		if (tmin > tmax)
			draw_swap(&tmin, &tmax);
	}
	else if ((tmin > 0.0) || (tmax < 0.0))
		return (1);
	else
	{
		tmin = (double)-INFINITY;
		tmax = (double)INFINITY;
	}
	if ((tmin > tb[1]) || (tmax < tb[0]))
		return (1);
	tb[0] = fmax(tb[0], tmin);
	tb[1] = fmin(tb[1], tmax);
	return (0);
}

int				raybox_check(t_ray *r, t_box *box)
{
	double			tb[2];
	const float		rx = (float)r->dir.x;
	const float		ry = (float)r->dir.y;
	const float		rz = (float)r->dir.z;

	tb[0] = (double)-INFINITY;
	tb[1] = (double)INFINITY;
	if (check(&(box->xmin), (float)r->start.x, rx, tb))
		return (0);
	if (tb[1] < 0.0)
		return (0);
	r->lenght = (tb[0] > 0.0) ? tb[0] : tb[1];
	if (check(&(box->ymin), (float)r->start.y, ry, tb))
		return (0);
	if (tb[1] < 0.0)
		return (0);
	r->lenght = (tb[0] > 0.0) ? tb[0] : tb[1];
	if (check(&(box->zmin), (float)r->start.z, rz, tb))
		return (0);
	if (tb[1] < 0.0)
		return (0);
	r->lenght = (tb[0] > 0.0) ? tb[0] : tb[1];
	return (1);
}

void			rt_box_update(t_obj *obj)
{
	const t_v4f		p = draw_convert_v4d_to_v4f(obj->trans.w);
	t_v4f			r;

	if (obj->type == CUBE)
	{
		r.x = ((t_cube*)(obj->content))->size / 2.0f;
		obj->hitbox = (t_box){p.x - r.x, p.x + r.x, p.y - r.x, p.y + r.x,
			p.z - r.x, p.z + r.x};
	}
	else if (obj->type == SPHERE)
	{
		r.x = ((t_sphere*)(obj->content))->radius;
		obj->hitbox = (t_box){p.x - r.x, p.x + r.x, p.y - r.x, p.y + r.x,
			p.z - r.x, p.z + r.x};
	}
	else if (obj->type == CONE)
	{
		r.x = (float)(((t_cone *)(obj->content))->angle.w);
		r.y = ((t_cone *)(obj->content))->size;
		obj->hitbox = (t_box){p.x - r.x * r.y, p.x + r.x * r.y, p.y - r.y,
			p.y, p.z - r.x * r.y, p.z + r.x * r.y};
	}
	else
		obj->hitbox = (t_box){0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
}
