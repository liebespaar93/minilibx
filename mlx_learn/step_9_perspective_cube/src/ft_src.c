/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:47:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 22:34:21 by kyoulee          ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}

void	*ft_zeromalloc(void **ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (new_ptr)
		ft_memset(new_ptr, 0, size);
	if (ptr)
		*ptr = new_ptr;
	return (new_ptr);
}
