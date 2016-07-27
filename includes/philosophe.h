/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegay <alegay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 09:11:47 by eseveno           #+#    #+#             */
/*   Updated: 2015/06/08 15:15:42 by alegay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHE_H
# define PHILOSOPHE_H
# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <SDL.h>
# include <stdlib.h>
# include <pthread.h>
# define MAX_LIFE 10
# define EAT_T 1
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 30
# define PHILO 7

typedef struct			s_data
{
	pthread_mutex_t		mutex[PHILO];
}						t_data;

typedef struct			s_env
{
	int					vie[PHILO];
	int					etat[PHILO];
	int					u;
	int					thd;
	int					eat;
	int					rest;
	SDL_Surface			*screen;
	SDL_Surface			*image1;
	SDL_Surface			*image2;
	SDL_Surface			*image3;
	SDL_Surface			*image4;
	SDL_Surface			*image5;
	SDL_Surface			*rectangle;
	SDL_Rect			position[8];
	SDL_Rect			r[7];
}						t_env;

void					ft_sdlinit();
void					*threadphilosophe(void *arg);
void					*threadcalc(void *arg);
void					ft_init();
int						ft_allvie();
void					ft_lose_life();
void					*threadphilosopheone(void *arg);
void					*threadphilo(void *arg);
void					ft_sdl();
void					ft_sdl2(int i);
void					ft_position(void);
void					ft_r(void);
void					oooo(int z, t_data *fourchette);
void					pppp(int z, t_data *fourchette);
void					ft_wait(void);
void					ft_wait_lose(void);
int						whoisdead();
void					ft_print(void);
t_env					g_e;
#endif
