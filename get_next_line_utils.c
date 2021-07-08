/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:58:43 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/07/07 22:16:36 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!(s))
		return (i);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

size_t	ft_strcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!(src))
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (*(src + i) != '\0' && i < size - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;

	if (!s1 && !s2)
		return (0);
	temp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!temp)
		return (0);
	ft_strcpy(temp, s1, (ft_strlen(s1) + 1));
	ft_strcpy((temp + ft_strlen(s1)), s2, (ft_strlen(s2) + 1));
	free(s1);
	return (temp);
}

char	*ft_strdup(char *s)
{
	char	*temp;

	temp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!temp)
		return (0);
	ft_strcpy(temp, s, ft_strlen(s) + 1);
	return (temp);
}
