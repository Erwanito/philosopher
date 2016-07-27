/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 14:08:44 by eseveno           #+#    #+#             */
/*   Updated: 2015/06/08 14:20:55 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

void		ft_sdl(void)
{
	SDL_Event event;

	ft_sdlinit();
	while (g_e.thd != 0)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				g_e.thd = 0;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					g_e.thd = 0;
				break ;
			}
		}
		ft_sdl2(0);
		if (g_e.thd == 3)
			ft_wait();
		if (g_e.thd == 4)
			ft_wait_lose();
	}
}

void		ft_sdl2(int i)
{
	SDL_FillRect(g_e.screen, NULL, SDL_MapRGB(g_e.screen->format, 0, 0, 0));
	while (i < 7)
	{
		g_e.rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,
			g_e.vie[i] * 100 / MAX_LIFE, 20, 32, 0, 0, 0, 0);
		SDL_FillRect(g_e.rectangle, NULL, SDL_MapRGB(g_e.screen->format,
			255, 255, 255));
		if (g_e.etat[i] == 1)
		{
			SDL_BlitSurface(g_e.rectangle, NULL, g_e.screen, &(g_e.r[i]));
			SDL_BlitSurface(g_e.image1, NULL, g_e.screen, &(g_e.position[i]));
		}
		if (g_e.etat[i] == 2)
		{
			SDL_BlitSurface(g_e.rectangle, NULL, g_e.screen, &(g_e.r[i]));
			SDL_BlitSurface(g_e.image3, NULL, g_e.screen, &(g_e.position[i]));
		}
		if (g_e.etat[i] == 0)
		{
			SDL_BlitSurface(g_e.rectangle, NULL, g_e.screen, &(g_e.r[i]));
			SDL_BlitSurface(g_e.image2, NULL, g_e.screen, &(g_e.position[i]));
		}
		i++;
	}
	SDL_Flip(g_e.screen);
}

void		ft_print(void)
{
	int			i;

	usleep(50);
	i = 0;
	ft_printf("-------------------------------------\n");
	while (i < PHILO)
	{
		if (g_e.etat[i] == 0)
		{
			ft_printf("philo[%d] dors et a %d de vie\n", i, g_e.vie[i]);
		}
		else if (g_e.etat[i] == 1)
		{
			ft_printf("philo[%d] mange et a %d de vie\n", i, g_e.vie[i]);
		}
		else
			ft_printf("philo[%d] reflechie et a %d de vie\n", i, g_e.vie[i]);
		i++;
	}
	ft_printf("-------------------------------------\n");
}
