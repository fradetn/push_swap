/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:41:14 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/04 22:59:46 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	stash = read_to_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = get_actual_line(stash);
	stash = trunc_actual_line(stash);
	return (line);
}

char	*read_to_stash(int fd, char	*stash)
{
	char	*buf;
	char	*tmp;
	int		nbread;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbread = 1;
	if (!buf)
		return (NULL);
	while (ft_strchr(stash, '\n') == NULL && nbread != 0)
	{
		nbread = read(fd, buf, BUFFER_SIZE);
		if ((*stash == '\0' && nbread == 0) || nbread == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[nbread] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		if (tmp)
			free(tmp);
	}
	free(buf);
	return (stash);
}

char	*get_actual_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * (ft_linelen(stash) + 2));
	if (!line)
		return (NULL);
	while (*stash && *stash != '\n')
		line[i++] = *stash++;
	if (*stash == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*trunc_actual_line(char *stash)
{
	char	*tmp;

	tmp = stash;
	stash = ft_strchr(stash, '\n');
	if (stash)
		stash = ft_strdup(stash + 1);
	else
		stash = NULL;
	free(tmp);
	return (stash);
}

int	ft_linelen(char *s)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != '\n')
		count++;
	return (count);
}

/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	char *line;
	int	fd = open("read_error.txt", O_RDONLY);

	
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	close(fd);
	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// char *line;

	// line = trunc_actual_line("dsdsdsdd");
	// printf("%s", line);
}*/