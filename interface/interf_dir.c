/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interf_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 00:20:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/07 00:21:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "objects.h"
#include "libft.h"
#include "sda.h"

char	*interf_getdir_x(t_obj *obj, t_sda_export *e)
{
	char	*str;

	(void)e;
	str = ft_dtoa(obj->trans.x.x, 6);
	if (!str)
		return (NULL);
	return (sda_double_short(str));
}

char	*interf_getdir_y(t_obj *obj, t_sda_export *e)
{
	char	*str;

	(void)e;
	str = ft_dtoa(obj->trans.y.y, 6);
	if (!str)
		return (NULL);
	return (sda_double_short(str));
}

char	*interf_getdir_z(t_obj *obj, t_sda_export *e)
{
	char	*str;

	(void)e;
	str = ft_dtoa(obj->trans.z.z, 6);
	if (!str)
		return (NULL);
	return (sda_double_short(str));
}
