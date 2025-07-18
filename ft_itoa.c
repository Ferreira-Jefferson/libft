/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:33:57 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/18 13:40:32 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	nb_count;
	char			*s;
	int 			count_decimal_places;

	nb = n;
	if (n < 0)
		nb = n * -1;
	count_decimal_places = 1;
	nb_count = nb;
	while ((nb_count /= 10) > 0)
		count_decimal_places++;
	s = (char *) malloc((count_decimal_places + (1 + (n < 0))) * sizeof(char));
	if(n < 0)
		s[0] = '-';
	s[count_decimal_places + (n < 0)] = '\0';
	while (count_decimal_places--)
	{
		s[count_decimal_places + (n < 0)] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);	
}

