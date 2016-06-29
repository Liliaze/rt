/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_setup_al.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:02:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/29 19:41:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sda.h"
#include "libft.h"
#include "render.h"
#include <math.h>

int			sda_setup_al(t_rt *rt, t_obj *obj, char **av)
{
	(void)obj;
	rt->settings.ambiant_light = fmin(1.0, ft_atod(av[0]) / MID_LIGHT_POWER);
	return (1);
}
