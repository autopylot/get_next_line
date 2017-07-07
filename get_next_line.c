/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 10:43:20 by wlin              #+#    #+#             */
/*   Updated: 2017/07/07 12:06:40 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	get_next_line(const int fd, char **line)
{
	static char		*save = "";
	char			*sptr;
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char 			*pos;

	if (fd < 0 || !line || (read(fd, buffer, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strdup(save);
	if ((pos = ft_strchr(*line, '\n')))
	{
		sptr = save;
		save = ft_strdup(pos + 1);
		*pos = '\0';
		free(sptr);
		return (1);
	}
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		sptr = *line;
		*line = ft_strjoin(*line, buffer);
		free(sptr);
		if ((pos = ft_strchr(*line, '\n')))
		{
			//sptr = save;
			save = ft_strdup(pos + 1);
			//free(sptr);
			*pos = '\0';
			return (1);
		}
	}
	return (ret == 0 ? 0 : -1);
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int retval;

	if (argc == 2)
	{
		puts(" ");
	}
	fd = open(argv[1], O_RDONLY);
	while ((retval = get_next_line(fd, &line)))
	{
		printf("%d ", retval);
		puts(line);
	}
	return (0);
}
