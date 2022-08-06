/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_2_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 16:32:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <ft_src.h>

t_mtx2	ft_mtx2_mult_mtx2(t_mtx2 m2_1, t_mtx2 m2_2)
{
	t_mtx2	new;

	new.m11 = m2_1.m11 * m2_2.m11 + m2_1.m12 * m2_2.m21;
	new.m12 = m2_1.m11 * m2_2.m12 + m2_1.m12 * m2_2.m22;
	new.m21 = m2_1.m21 * m2_2.m11 + m2_1.m22 * m2_2.m21;
	new.m22 = m2_1.m21 * m2_2.m12 + m2_1.m22 * m2_2.m22;
	return (new);
}

t_mtx2	ft_mtx2_shear(float x, float y)
{
	t_mtx2	new;

	new.m11 = 1;
	new.m12 = y;
	new.m21 = x;
	new.m22 = 1;
	return (new);
}
