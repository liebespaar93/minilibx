/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:47:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 18:26:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_src.h>

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_sign(float num)
{
	if (num < 0)
		return (-1);
	return (1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if ((dst == (void *)0) && (src == (void *)0))
		return ((void *)0);
	while (n-- > 0)
		*dptr++ = *sptr++;
	return (dst);
}
