/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:47:01 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 01:50:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SRC_H
# define FT_SRC_H

# define C_PI	3.14159265358979323846264338327950288

# include <stdlib.h>

/* ft_src */
float	ft_abs(float num);
int		ft_sign(float num);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_zeromalloc(void **ptr, size_t size);

/* ft_src2 */
double	ft_min(double value1, double value2);
double	ft_max(double value1, double value2);
double	ft_cycle(double value, double cycle);
/* ft_src_ptr */
void	*ft_ptrcpy(void **ptr, void *cpy_ptr);

/* ft_sin */
double	ft_sin(double angle);
double	ft_sin_plus(double angle1, double angle2);
double	ft_sin_minus(double angle1, double angle2);
double	ft_cosec(double angle);

/* ft_cos */
double	ft_cos(double angle);
double	ft_cos_plus(double angle1, double angle2);
double	ft_cos_minus(double angle1, double angle2);
double	ft_sec(double angle);

/* ft_tan */
double	ft_tan(double angle);
double	ft_tan_plus(double angle1, double angle2);
double	ft_tan_minus(double angle1, double angle2);
double	ft_cot(double angle);

#endif
