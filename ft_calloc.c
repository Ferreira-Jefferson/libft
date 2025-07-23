/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:31:30 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/23 11:31:32 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*p;

	if (!size || !number)
		return (ft_strdup(""));
	if (size && number > (size_t)-1 / size)
		return (NULL);
	p = (void *) malloc(number * size);
	if (!p)
		return (NULL);
	p = ft_memset(p, 0, number * size);
	return (p);
}
