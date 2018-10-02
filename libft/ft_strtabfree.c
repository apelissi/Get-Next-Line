/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:26:06 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/06 14:49:13 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabfree(char **tab)
{
	size_t	t;

	t = 0;
	if (tab)
	{
		while (tab[t])
		{
			free(tab[t]);
			tab[t] = NULL;
		}
		tab = NULL;
	}
}
