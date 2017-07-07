/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:33:18 by wlin              #+#    #+#             */
/*   Updated: 2017/07/07 12:04:04 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

#define BUFF_SIZE 9999

int			get_next_line(int const fd, char **line);

#endif
