/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_export_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 14:24:34 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/16 02:13:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sda.h"
#include "libft.h"

static char	*sda_xyz_short(char *s)
{
	char	*so;

	so = s;
	while (*s)
		s++;
	s--;
	while ((s > so) && (*s == '0'))
		*(s--) = '\0';
	if (*s == '.')
		*s = '\0';
	return (so);
}

char		*sda_export_xyz(const t_v4d *v, char radians)
{
	char	*x;
	char	*y;
	char	*z;
	char	*buff;

	if ((v->x == 0.0) && (v->y == 0.0) && (v->z == 0.0))
		return (NULL);
	x = sda_xyz_short(ft_dtoa((radians) ? rad2deg(v->x): v->x, 6));
	y = sda_xyz_short(ft_dtoa((radians) ? rad2deg(v->y): v->y, 6));
	z = sda_xyz_short(ft_dtoa((radians) ? rad2deg(v->z): v->z, 6));
	buff = ft_strmjoin(5, x, " ", y, " ", z);
	ft_mfree(3, x, y, z);
	return (buff);
}

char		*sda_export_pos(t_obj *obj)
{
	return (sda_export_xyz(&obj->trans.w, 0));
}

char	*sda_export_rot(t_obj *obj)
{
	return (sda_export_xyz(&obj->rotation, 1));
}
