/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolo_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 20:51:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/18 15:01:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"
#include "parser.h"

int					yolo_setup_realpos(t_obj *obj, int mode, void *userdata)
{
	(void)userdata;
	(void)mode;
	if ((!obj->parent) || (obj->type == CAMERA))
		return (OK);
	obj->trans = draw_matrix_multiply_axes_m4(
		obj->rotation,
		(t_v4d){1.0, 1.0, 1.0, 1.0}, obj->trans.w);
	rt_box_update(obj);
	return (OK);
}

int					yolo_setup(t_obj *obj, size_t ac, char **av)
{
	int					p;
	const t_parser_cfg	parse[] = {
		(t_parser_cfg){SPHERE | CUBE, &yolo_setup_cube},
		(t_parser_cfg){CAMERA, &yolo_setup_camera},
		(t_parser_cfg){PLAN, &yolo_setup_plan},
		(t_parser_cfg){CONE, &yolo_setup_cone},
		(t_parser_cfg){CYL, &yolo_setup_cyl},
		(t_parser_cfg){POINTLIGHT | SPOT, &yolo_setup_plight}
	};

	if (!ac)
		return (1);
	p = 6;
	while (p--)
		if (obj->type & parse[p].type)
			return (parse[p].config(obj, ac, av));
	return (0);
}
