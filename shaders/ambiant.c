/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:19:21 by alhote            #+#    #+#             */
/*   Updated: 2016/07/11 18:31:15 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "shaders.h"

void			shader_ambiant(t_shader *s, t_render *r, t_obj *light)
{
	(void)light;
	s->color_render = blend_multiply(
	((t_cube*)(r->obj_intersect->content))->color, 0xFFFFFF);
}