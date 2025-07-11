/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 08:34:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/11 11:35:33 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	void			*head;

	head = dest;
	while (len--)
	{
		*(unsigned char *) dest = (unsigned char) c;
		dest++;
	}
	return (head);
}
