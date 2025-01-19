/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:50:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/19 11:24:31 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// File Descriptor Requirements (Linux Systems) : 
// Max open files limit: default value of 1024 (some versions in Linux)
// source : command (ulimit -n) in terminal, in vscode its not accurate
// After the directory server has exceeded the fd limit of 1024 per process
// any new process and worker threads will be blocked.
char	*get_next_line(int fd)
{
	char		*line;
	static char	*call[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	call[fd] = ft_reading(fd, call[fd]);
	if (!call[fd])
		return (NULL);
	line = ft_extract(call[fd]);
	if (!line)
	{
		free(call[fd]);
		return (NULL);
	}
	call[fd] = ft_storage(call[fd]);
	return (line);
}

char	*ft_reading(int fd, char *call)
{
	char	*buffer;
	ssize_t	readline;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readline = 1;
	while (ft_strchr(call, '\n') == NULL && readline != 0)
	{
		readline = read(fd, buffer, BUFFER_SIZE);
		if (readline == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (readline == 0)
			break ;
		buffer[readline] = '\0';
		call = ft_joining(call, buffer);
	}
	free (buffer);
	return (call);
}

char	*ft_joining(char *call, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(call, buffer);
	if (!temp)
	{		
		free (call);
		free (buffer);
		return (NULL);
	}
	free (call);
	call = temp;
	return (call);
}

char	*ft_extract(char *call)
{
	char	*line;
	int		i;

	if (call == NULL || call[0] == '\0')
		return (NULL);
	i = 0;
	while (call[i] != '\n' && call[i])
		i++;
	if (call[i] == '\n')
		line = ft_substr(call, 0, i + 1);
	else
		line = ft_substr(call, 0, i);
	return (line);
}

char	*ft_storage(char *call)
{
	char	*leftover;
	int		i;

	if (!call)
	{
		free(call);
		return (NULL);
	}
	i = 0;
	while (call[i] && call[i] != '\n')
		i++;
	if (call[i] == '\n')
		leftover = ft_strdup(&call[i + 1]);
	else
		leftover = NULL;
	free (call);
	return (leftover);
}

// // int open(const char *pathname, int flags);
// // int close(int fd);
// // open, close, printf & perror
// # include <fcntl.h>
// # include <unistd.h>
// # include <stdio.h>

// int	main()
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	int		i;

// 	printf("Opening files\n");
// 	fd1 = open("tests/test1.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	i = 1;
// 	line1 = get_next_line(fd1);
// 	line2 = get_next_line(fd2);
// 	line3 = get_next_line(fd3);
// 	while (line1 || line2 || line3 || i < 10)
// 	{
// 		printf("File1, Line %d: %s\n", i, line1);
// 		printf("File2, Line %d: %s\n", i, line2);
// 		printf("File3, Line %d: %s\n", i, line3);
// 		free (line1);
// 		free (line2);
// 		free (line3);
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		line3 = get_next_line(fd3);
// 		i++;
// 		if (!line1 && !line2 && !line3)
// 			break ;
// 	}

// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	printf("File closed\n");
// }
