/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3 product.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:46:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/08 08:51:42 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_vector.h>
#include <ft_src.h>

float	ft_vec3_dot(t_vec3 v3_1, t_vec3 v3_2)
{
	float	length;

	length = v3_1.x * v3_2.x + v3_1.y * v3_2.y + v3_1.z * v3_2.z;
	return (length);
}

t_vec3	ft_vec3_cross(t_vec3 v3_1, t_vec3 v3_2)
{
	t_vec3	new;

	new.x = v3_1.y * v3_2.z - v3_1.z * v3_2.y;
	new.y = v3_1.z * v3_2.x - v3_1.x * v3_2.z;
	new.z = v3_1.x * v3_2.y - v3_1.y * v3_2.x;
	return (new);
}

