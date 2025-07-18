/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:33:57 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/18 10:23:07 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_signal(int n, char **s, unsigned int *nb)
{
	if (n < 0)
	{
		*s = ft_strdup("-");
		*nb = n * -1;
	}
	else
	{
		*s = ft_strdup("");
		*nb = n;
	}
	return (*s != NULL);
}

char	*get_minus_ten(unsigned int nb, char *s)
{
	char	*ss;
	char	num[2];

	num[0] = nb + '0';
	num[1] = '\0';
	ss = ft_strjoin(s, num);
	return (ss);
}

char	*ft_itoa(int n)
{
	char			*s;
	char			*it;
	char			*ss;
	unsigned int	nb;
	char			num[2];

	if (!get_signal(n, &s, &nb))
		return (NULL);
	if (nb < 10)
	{
		ss = get_minus_ten(nb, s);
		free(s);
		return (ss);
	}
	num[0] = (nb % 10) + '0';
	num[1] = '\0';
	it = ft_itoa(nb / 10);
	ss = ft_strjoin(s, it);
	free(s);
	s = ft_strjoin(ss, num);
	free(it);
	free(ss);
	return (s);
}
