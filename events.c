/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 23:17:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/01 20:49:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "draw.h"
#include "libft.h"

static void		display(t_rt *rt)
{
	rt_rays(rt);
	SDL_UpdateWindowSurface(rt->sys.win);
}

static void		rotate_camera(t_rt *rt, t_v3f deg)
{
	t_obj		*cam;

	cam = rt->root->content;
	(void)cam;
	(void)deg;
	//cam->trans.w = draw_vector_add(cam->trans.offset, deg);
}

int				keydown(int keycode, t_rt *rt)
{
	if (keycode == SDLK_ESCAPE)
		return (1);
	else if (keycode == SDLK_d)
	{
		((t_obj*)rt->root->content)->trans.w.x += 0.1;
		(void)rotate_camera;
		//rotate_camera(rt, (t_v3f){0.1f, 0.0f, 0.0f});
	}
	else if (keycode == SDLK_a)
		((t_obj*)rt->root->content)->trans.w.x -= 0.1;
	else if (keycode == SDLK_o)
	{
		ft_putstr("camera offset -> ");
		draw_putv4f(((t_obj*)rt->root->content)->trans.w, 6);
		ft_putchar('\n');
	}
	display(rt);
	return (0);
}

int				keyrlz(int keycode, t_rt *rt)
{
	(void)keycode;
	(void)rt;
	return (0);
}

int				sdl_event(SDL_Event *event, t_rt *rt)
{
	if (event->type == SDL_QUIT)
		return (1);
	else if ((event->type == SDL_WINDOWEVENT) &&
		(event->window.event == SDL_WINDOWEVENT_RESIZED))
	{
		rt->sys.geometry = draw_make_px(event->window.data1,
			event->window.data2);
		if (!(rt->sys.screen = SDL_GetWindowSurface(rt->sys.win)))
			return (2);
	}
	else if (event->type == SDL_KEYDOWN)
		return (keydown(event->key.keysym.sym, rt));
	else if (event->type == SDL_KEYUP)
		return (keyrlz(event->key.keysym.sym, rt));
	return (0);
}
