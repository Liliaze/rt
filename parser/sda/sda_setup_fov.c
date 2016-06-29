/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_setup_fov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:45:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/29 18:56:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sda.h"
#include "libft.h"
#define MINFOV 5.0
#define MAXFOV 180.0

int			sda_setup_fov(t_rt *rt, t_obj *obj, char **av)
{
	double	fov;

	(void)rt;
	fov = ft_atod(av[0]);
	if ((fov == 0.0) || (fov < MINFOV) || (fov > MAXFOV))
		fov = 49.124;
	((t_camera*)obj->content)->fov = deg2rad(fov);
	return (1);
}
