/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 08:34:48 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/11 11:24:44 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *dest, int c, unsigned int len)
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
