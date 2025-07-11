/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 08:34:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/11 09:55:21 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *dest, int c, unsigned int len)
{
	unsigned int	i;
	void			*head;

	head = dest;
	i = 0;
	while (i < len)
	{
		*(unsigned char *) dest = (unsigned char) c;
		dest++;
		i++;
	}
	return (head);
}
