/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 01:49:47 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <ft_src.h>

t_mtx2	ft_matrix_2(float m11, float m12, float m21, float m22)
{
	t_mtx2	new;

	new.m11 = m11;
	new.m12 = m12;
	new.m21 = m21;
	new.m22 = m22;
	return (new);
}

t_vec2	ft_mtx2_mult_vec2(t_mtx2 m2, t_vec2 v2)
{
	t_vec2	temp;

	temp.x = v2.x * m2.m11 + v2.y * m2.m12;
	temp.y = v2.x * m2.m21 + v2.y * m2.m22;
	return (temp);
}

t_vec2	ft_vec2_mult_mtx2(t_vec2 v2, t_mtx2 m2)
{
	t_vec2	temp;

	temp.x = v2.x * m2.m11 + v2.y * m2.m21;
	temp.y = v2.x * m2.m12 + v2.y * m2.m22;
	return (temp);
}

t_mtx2	ft_mtx2_mult_scalar(t_mtx2 m2, float scalar)
{
	m2.m11 *= scalar;
	m2.m12 *= scalar;
	m2.m21 *= scalar;
	m2.m22 *= scalar;
	return (m2);
}

t_mtx2	ft_mtx2_angle(float angle)
{
	t_mtx2		new;
	double		sin;
	double		cos;

	sin = ft_sin(angle);
	cos = ft_cos(angle);
	new = ft_matrix_2(cos, -sin, sin, cos);
	return (new);
}
