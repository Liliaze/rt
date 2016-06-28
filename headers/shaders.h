/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:34:04 by alhote            #+#    #+#             */
/*   Updated: 2016/06/28 22:38:40 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADERS_H
# define SHADERS_H
# include "rt.h"
# include "render.h"

typedef struct		s_shaders
{
	unsigned int	nbr_fshaders;
	int				(*vertex_shader)(t_render *r, t_obj *o);
	void			(**fragment_shader)(t_render *r, t_obj *o);
}					t_shaders;

t_shaders			*init_shader(unsigned int nbr_fshaders);
int					exec_fshaders(t_shaders *s, t_render *r, t_obj *o);
double				rt_reflection(t_render *r, t_obj *light);

#endif
