/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 06:15:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/29 19:05:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

t_type			rt_gettype(const char *str)
{
	const t_typecmp	types[] = {
		{CUBE, "CUBE"},
		{PLAN, "PLAN"},
		{SPHERE, "SPHERE"},
		{ROOT, "ROOT"},
		{SPOT, "SPOT"},
		{CAMERA, "CAMERA"},
		{POINTLIGHT, "POINTLIGHT"},
		{FACE, "FACE"},
		{EMPTY, "EMPTY"},
		{CONE, "CONE"},
		{CYL, "CYL"},
		{SUNLIGHT, "SUNLIGHT"},
		{SETTING, "SETTING"}
	};
	int				p;

	p = 13;
	while ((p--) && (ft_strcmp(types[p].str, str)))
		;
	return ((p < 0) ? INVALID : types[p].type);
}

void			rt_puttype(int type)
{
	const t_typecmp	types[] = {
		{CUBE, "CUBE"},
		{PLAN, "PLAN"},
		{SPHERE, "SPHERE"},
		{ROOT, "ROOT"},
		{SPOT, "SPOT"},
		{CAMERA, "CAMERA"},
		{POINTLIGHT, "POINTLIGHT"},
		{FACE, "FACE"},
		{EMPTY, "EMPTY"},
		{INVALID, "INVALID"},
		{CONE, "CONE"},
		{CYL, "CYLINDRE"},
		{SUNLIGHT, "SUNLIGHT"},
		{SETTING, "SETTING"}
	};
	int				p;

	p = 14;
	while ((p--) && (types[p].type != type))
		;
	ft_putstr((p < 0) ? "UNKNOW" : types[p].str);
}
