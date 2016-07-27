/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 15:40:32 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:24 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_realloc(char *str, int size)
{
	char		*new;
	int			i;

	if (size == 0)
		return (str);
	i = ft_strlen(str);
	if ((new = (char *)malloc((i + size + 1) * sizeof(*str))) == NULL)
		return (NULL);
	*new = '\0';
	ft_strcat(new, str);
	*str = '\0';
	free(str);
	return (new);
}
