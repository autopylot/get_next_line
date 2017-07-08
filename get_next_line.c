/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 10:43:20 by wlin              #+#    #+#             */
/*   Updated: 2017/07/07 19:21:47 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int ft_check_nl(char **line, char **save)
{
	char	*pos;

	if((pos = ft_strchr(*line, '\n')))
	{
		if (*(*save))
			free(*save);
		*save = ft_strdup(pos + 1);
		*pos = '\0';
		if (*(*save) == "")
			free(*save);
		return (1);
	}
	return (0);
}


int	get_next_line(const int fd, char **line)
{
	static char		*save = "";
	char			*sptr;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || (read(fd, buffer, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strdup(save);
	if (ft_check_nl(line, &save))
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		sptr = *line;
		*line = ft_strjoin(*line, buffer);
		free(sptr);
		if (ft_check_nl(line, &save))
			return (1);
	}
	if (ret == 0 && ft_strlen(*line))
		return (1);

}

// int main(int argc, char **argv)
// {
// 	char *line;
// 	int fd;
// 	int retval;
//
// 	if (argc != 2)
// 		return (1);
// 	fd = open(argv[1], O_RDONLY);
// 	while ((retval = get_next_line(fd, &line)))
// 	{
// 		printf("%d %s\n", retval, line);
// 		free(line);
// 	}
// 	return (0);
// }
