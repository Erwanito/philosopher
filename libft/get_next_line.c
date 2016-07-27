/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:55:27 by eseveno           #+#    #+#             */
/*   Updated: 2015/06/01 17:44:44 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "./includes/libft.h"

static int		check_line(char *line, char *buff)
{
	int			nb;

	nb = 0;
	while (line[nb] != '\0')
	{
		if (line[nb] == '\n')
		{
			line[nb] = '\0';
			*buff = '\0';
			ft_strcat(buff, &line[nb + 1]);
			return (-1);
		}
		nb++;
	}
	*buff = '\0';
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	static char	buff[BUFF_SIZE];

	if (fd < 0 || (*line = (char *)malloc(BUFF_SIZE * sizeof(**line))) == NULL)
		return (-1);
	**line = '\0';
	ft_strcat(*line, buff);
	*buff = '\0';
	i = BUFF_SIZE;
	while (check_line(*line, buff) != -1 && i == BUFF_SIZE)
	{
		if ((i = read(fd, buff, BUFF_SIZE)) == -1)
		{
			free(*line);
			return (-1);
		}
		buff[i] = '\0';
		*line = ft_realloc(*line, i);
		ft_strcat(*line, buff);
	}
	if (**line == '\0' && ft_strlen(buff) == 0 && i != BUFF_SIZE)
		return (0);
	return (1);
}
