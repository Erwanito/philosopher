/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:16:32 by eseveno           #+#    #+#             */
/*   Updated: 2015/06/08 14:20:12 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

int			main(int ac, char **av)
{
	t_data		f;
	int			t;
	pthread_t	*threads;

	(void)ac;
	(void)av;
	if (PHILO >= 7)
	{
		threads = (pthread_t *)malloc(sizeof(pthread_t) * PHILO);
		ft_init(&f);
		t = time(NULL);
		while (t == time(NULL))
			;
		pthread_create(&threads[0], NULL, threadphilosopheone, (void*)&f);
		while (g_e.u < PHILO)
		{
			pthread_create(&threads[g_e.u], NULL, threadphilo, (void*)&f);
			usleep(150);
			g_e.u++;
		}
		pthread_create(&threads[7], NULL, threadcalc, (void*)&g_e);
		ft_sdl();
		SDL_Quit();
	}
	return (0);
}

void		*threadphilosopheone(void *arg)
{
	t_data		*fourchette;

	fourchette = (t_data*)arg;
	while (1)
	{
		pthread_mutex_lock(&fourchette->mutex[PHILO - 1]);
		g_e.etat[0] = 2;
		pthread_mutex_lock(&fourchette->mutex[0]);
		g_e.etat[0] = 1;
		usleep(g_e.eat * 1000000);
		g_e.vie[0] = MAX_LIFE;
		g_e.etat[0] = 0;
		pthread_mutex_unlock(&fourchette->mutex[PHILO - 1]);
		pthread_mutex_unlock(&fourchette->mutex[0]);
		usleep(g_e.rest * 1000000);
	}
	return (arg);
}

void		*threadphilo(void *arg)
{
	int			z;
	t_data		*fourchette;

	z = g_e.u;
	fourchette = (t_data*)arg;
	while (1)
	{
		pppp(z, fourchette);
		g_e.etat[z] = 1;
		usleep(g_e.eat * 1000000);
		g_e.vie[z] = MAX_LIFE;
		g_e.etat[z] = 0;
		oooo(z, fourchette);
		usleep(g_e.rest * 1000000);
	}
	return (arg);
}

void		*threadcalc(void *arg)
{
	int	t;
	int	i;

	i = 0;
	t = time(NULL);
	while (i < TIMEOUT)
	{
		if (t != time(NULL))
		{
			ft_print();
			t = time(NULL);
			ft_lose_life(g_e);
			i++;
		}
		if (ft_allvie() != 1)
		{
			ft_printf("Philo est mort");
			g_e.thd = 4;
			return (arg);
		}
	}
	ft_printf("It's time to dance");
	g_e.thd = 3;
	return (arg);
}

void		ft_lose_life(void)
{
	int	i;

	i = 0;
	while (i < PHILO)
	{
		g_e.vie[i]--;
		i++;
	}
}
