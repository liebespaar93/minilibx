/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:18:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/08 09:43:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <ft_src.h>

t_vec3	ft_vec3_sum(t_vec3 v3_1, t_vec3 v3_2)
{
	v3_1.x += v3_2.x;
	v3_1.y += v3_2.y;
	v3_1.z += v3_2.z;
	return (v3_1);
}

t_vec3	ft_vec3_minus(t_vec3 v3_1, t_vec3 v3_2)
{
	v3_1.x -= v3_2.x;
	v3_1.y -= v3_2.y;
	v3_1.z -= v3_2.z;
	return (v3_1);
}

t_vec3	ft_vec3_mult(t_vec3 v3, float scalar)
{
	v3.x *= scalar;
	v3.y *= scalar;
	v3.z *= scalar;
	return (v3);
}