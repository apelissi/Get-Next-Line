/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:47:42 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 22:15:53 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_GET_NEXT_LINE_H
#	define FT_GET_NEXT_LINE_H

#include "libft/libft.h"
#define BUFF_SIZE 1
#define SEP '\n'

int		get_next_line(const int fd, char **line);

#	endif
