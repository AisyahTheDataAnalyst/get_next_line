/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:43:27 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/14 20:12:12 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// define need to have 1 space in default
// to mean its referring to its ifndef
// ifndef and endif has no space by default
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// this 2nd inclusion guard here has one extra spaces than normal to mean that 
// this is the 2nd thing to be defined. 
// now, we're defining specifically BUFFER_SIZE into 42
// must place this within 
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