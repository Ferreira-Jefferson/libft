/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 08:29:23 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/25 13:01:19 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*aux_s;

	aux_s = (char *) s;
	while (*aux_s)
	{
		if (*aux_s == (char)c)
			return (aux_s);
		aux_s++;
	}
	if (c == '\0')
		return (aux_s);
	return (NULL);
}
