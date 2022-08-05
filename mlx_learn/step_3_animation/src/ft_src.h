/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:47:01 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 20:46:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SRC_H
# define FT_SRC_H

# include <stdlib.h>

/* ft_src */
float	ft_abs(float num);
int		ft_sign(float num);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_zeromalloc(void **ptr, size_t size);

/* ft_src_ptr */
void	*ft_ptrcpy(void **ptr, void *cpy_ptr);

#endif
