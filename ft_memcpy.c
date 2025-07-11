/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:35:57 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/11 13:29:16 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *ptr;
	
	ptr = (unsigned char *) src;
	while(len--)
	{
		*(unsigned char *) dst = *ptr;
		dst++;
		ptr++;
	}
	return (dst);
}