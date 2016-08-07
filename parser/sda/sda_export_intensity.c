/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_export_intensity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 00:34:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/08 00:13:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sda.h"
#include "libft.h"
#include "forms.h"

char	*sda_export_intensity(t_obj *obj, t_sda_export *e)
{
	(void)e;
	return (sda_double_short(ft_dtoa(((t_plight*)obj->content)->intensity, 6)));
}
