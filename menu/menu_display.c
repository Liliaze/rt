/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 15:47:21 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/22 11:55:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "menu.h"
#include "libft.h"
#include "keyboard.h"

static void 	menu_degrade(SDL_Surface *surface,
	const unsigned int scolor, const unsigned int ecolor)
{
	int				line;
	int				col;
	float			pc;
	unsigned int	*pixels;

	col = surface->w;
	while (col--)
	{
		pc = (float)col / (float)surface->w;
		((unsigned int *)surface->pixels)[col] = draw_color_lerp(scolor, ecolor,
			pc);
	}
	line = surface->h;
	while (line-- > 1)
	{
		pixels = &((unsigned int *)surface->pixels)[line * surface->w];
		ft_memcpy(pixels, surface->pixels,
			(size_t)surface->w * sizeof(unsigned int));
	}
}

void			menu_display(t_rt *rt)
{
	size_t			max_size = (size_t)(rt->menu.items.x * rt->menu.items.y);
	size_t			size;
	t_point			px;
	size_t			p;

	size = (rt->rts_size < max_size) ? rt->rts_size : max_size;
	p = 0;
	menu_degrade(rt->sys.screen, 0xe97313, 0x000000);
	px = (t_point){MENU_PADDING_X, MENU_PADDING_Y};
	while (p < size)
	{
		if (movemyass(&rt->rts[p]))
			rt_rays(&rt->rts[p]);
		draw_blitsurface(rt->sys.screen, rt->rts[p].sys.screen, px);
		if (((p + 1) % (size_t)rt->menu.items.x == 0) && (p))
		{
			px.y += MENU_BORDER_Y + rt->rts[p].sys.geometry.y;
			px.x = MENU_PADDING_X;
		}
		else
			px.x += MENU_BORDER_X + rt->rts[p].sys.geometry.x;
		p++;
	}
}
