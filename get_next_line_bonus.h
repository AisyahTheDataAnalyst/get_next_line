/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:50:01 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/15 16:23:23 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

// read, malloc & free & NULL, ssize_t, size_t, SIZE_MAX
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdint.h>

// in utils (taken from libft)
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

// in get_next_line.c
char	*get_next_line(int fd);
char	*ft_reading(int fd, char *call);
char	*ft_joining(char *call, char *buffer);
char	*ft_extract(char *call);
char	*ft_storage(char *call);
#endif