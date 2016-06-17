/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 00:08:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/17 17:15:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "forms.h"
# include "rt.h"

# define MID_LIGHT_POWER 100.0
# define MAX_LIGHT_POWER 800.0

typedef struct	s_render
{
	t_ray		*ray;
	t_rt		*rt;
	t_obj		*obj_intersect;
	double		lowest_lenght;
	double		light_lenght;
	t_v4d		intersection;
	double		light_power;
}				t_render;

#endif
