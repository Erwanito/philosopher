/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 14:09:15 by eseveno           #+#    #+#             */
/*   Updated: 2015/06/08 14:17:31 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

void		ft_sdlinit(void)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		g_e.position[i].w = 100;
		g_e.position[i].h = 100;
		g_e.r[i].w = 100;
		g_e.r[i].h = 20;
		i++;
	}
	ft_position();
	ft_r();
	SDL_Init(SDL_INIT_VIDEO);
	g_e.screen = NULL;
	g_e.eat = EAT_T;
	g_e.rest = REST_T;
	g_e.screen = NULL;
	g_e.screen = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
	g_e.image1 = SDL_LoadBMP("./img/manger.bmp");
	g_e.image2 = SDL_LoadBMP("./img/dodo.bmp");
	g_e.image3 = SDL_LoadBMP("./img/reflechi.bmp");
	g_e.image4 = SDL_LoadBMP("./img/dance.bmp");
	g_e.image5 = SDL_LoadBMP("./img/mort.bmp");
}

void		ft_position(void)
{
	g_e.position[0].x = 100;
	g_e.position[0].y = 600;
	g_e.position[1].x = 100;
	g_e.position[1].y = 333;
	g_e.position[2].x = 450;
	g_e.position[2].y = 100;
	g_e.position[3].x = 800;
	g_e.position[3].y = 333;
	g_e.position[4].x = 800;
	g_e.position[4].y = 600;
	g_e.position[5].x = 700;
	g_e.position[5].y = 900;
	g_e.position[6].x = 300;
	g_e.position[6].y = 900;
	g_e.position[7].x = 300;
	g_e.position[7].y = 450;
}

void		ft_r(void)
{
	g_e.r[0].x = 100;
	g_e.r[0].y = 560;
	g_e.r[1].x = 100;
	g_e.r[1].y = 293;
	g_e.r[2].x = 450;
	g_e.r[2].y = 60;
	g_e.r[3].x = 800;
	g_e.r[3].y = 293;
	g_e.r[4].x = 800;
	g_e.r[4].y = 560;
	g_e.r[5].x = 700;
	g_e.r[5].y = 860;
	g_e.r[6].x = 300;
	g_e.r[6].y = 860;
}

void		ft_init(t_data *fourchette)
{
	int	i;

	i = 0;
	g_e.u = 1;
	g_e.thd = 1;
	while (i < PHILO)
	{
		pthread_mutex_init(&fourchette->mutex[i], NULL);
		g_e.vie[i] = MAX_LIFE;
		i++;
	}
}

int			ft_allvie(void)
{
	int	i;

	i = 0;
	while (i < PHILO)
	{
		if (g_e.vie[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
