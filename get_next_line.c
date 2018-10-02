/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:47:51 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 22:09:49 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_sbtlejoin(char *old, char *ajout, int lu)
{
	char	*new;

	ajout[lu] = '\0';
	if (!old && !ajout)
		return (NULL);
	else if (!old)
		return (ft_strdup(ajout));
	else if (!ajout)
		return (old);
	new = ft_strjoin(old, ajout);
	return (new);
}

t_list		*find_live(int fd, t_list **svg)
{
	t_list	*tmp;

	if (!svg)
		return (NULL);
	tmp = *svg;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstinit("", fd, NULL);
	ft_lstadd(svg, tmp);
	return (tmp);
}

int			lecture(int fd, char **str)
{
	int		lu;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((lu = read(fd, buf, BUFF_SIZE)))
	{
		tmp = *str;
		if (!(*str = ft_sbtlejoin(*str, buf, lu)))
			return (-1);
		if (tmp && *tmp)
			free(tmp);
		if (ft_strchr(buf, SEP))
			break ;
	}
	return (lu);
}

int			get_line(char **line, char *content, char c)
{
	int	i;

	i = ft_strlchr(content, c);
	if (i >= 0)
		*line = ft_strndup(content, i);
	else
		*line = ft_strdup(content);
	return (ft_strlen(*line));
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*svg;
	t_list			*live;
	int				lu;
	char			*sub;

	sub = NULL;
	if (line == NULL || read(fd, sub, 0) < 0 || !(live = find_live(fd, &svg)))
		return (-1);
	sub = live->content;
	lu = lecture(fd, &sub);
	live->content = sub;
	if (!*sub && !lu)
		return (0);
	lu = get_line(line, live->content, SEP);
	if (sub[lu] != '\0')
	{
		live->content = ft_strdup(&((live->content)[lu + 1]));
		free(sub);
	}
	else
		sub[0] = '\0';
	return (1);
}
