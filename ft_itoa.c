/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:33:57 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/16 17:27:13 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	char			num[2];

	s = ft_strdup("");
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s = ft_strjoin(s, "-");
		nb = n * -1;
	}
	else
		nb = n;
	if (nb < 10)
	{
		num[0] = nb + '0';
		num[1] = '\0';
		return (ft_strjoin(s, num));
	}
	num[0] = (nb % 10) + '0';
	num[1] = '\0';
	s = ft_strjoin(s, ft_itoa(nb / 10));
	return (ft_strjoin(s, num));
}
