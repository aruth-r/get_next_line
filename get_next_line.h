/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:59:33 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/07/05 19:06:30 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
size_t	ft_strcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		get_next_line(int fd, char **line);

#endif
