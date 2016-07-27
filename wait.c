/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 14:09:04 by eseveno           #+#    #+#             */
/*   Updated: 2015/06/08 14:48:44 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

int			whoisdead(void)
{
	int i;

	i = 0;
	while (g_e.vie[i] != 0)
		i++;
	return (i);
}

void		ft_wait_lose(void)
{
	SDL_Event	event;
	int			i;

	i = whoisdead();
	SDL_BlitSurface(g_e.image5, NULL, g_e.screen, &(g_e.position[i]));
	g_e.rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,
			0, 20, 32, 0, 0, 0, 0);
	SDL_FillRect(g_e.rectangle, NULL, SDL_MapRGB(g_e.screen->format,
			0, 0, 0));
	SDL_BlitSurface(g_e.rectangle, NULL, g_e.screen, &(g_e.r[i]));
	SDL_Flip(g_e.screen);
	while (SDL_WaitEvent(&event))
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
}

void		ft_wait(void)
{
	SDL_Event event;

	SDL_BlitSurface(g_e.image4, NULL, g_e.screen, &(g_e.position[7]));
	SDL_Flip(g_e.screen);
	while (SDL_WaitEvent(&event))
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
}

void		pppp(int z, t_data *fourchette)
{
	if ((z % 2) != 0)
	{
		pthread_mutex_lock(&fourchette->mutex[z - 1]);
		g_e.etat[z] = 2;
		pthread_mutex_lock(&fourchette->mutex[z]);
	}
	else
	{
		pthread_mutex_lock(&fourchette->mutex[z]);
		g_e.etat[z] = 2;
		pthread_mutex_lock(&fourchette->mutex[z - 1]);
	}
}

void		oooo(int z, t_data *fourchette)
{
	if ((z % 2) != 0)
	{
		pthread_mutex_unlock(&fourchette->mutex[z - 1]);
		pthread_mutex_unlock(&fourchette->mutex[z]);
	}
	else
	{
		pthread_mutex_unlock(&fourchette->mutex[z]);
		pthread_mutex_unlock(&fourchette->mutex[z - 1]);
	}
}
