/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:18:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/08 09:35:55 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <ft_src.h>

t_vec3	ft_vector_3(float x, float y, float z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

float	ft_vec3_length(t_vec3 v3)
{
	float	temp;

	temp = ft_sqrt(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
	return (temp);
}

t_vec3	ft_vec3_normalize(t_vec3 v3)
{
	float	length;

	length = ft_vec3_length(v3);
	v3.x = v3.x / length;
	v3.y = v3.y / length;
	v3.z = v3.z / length;
	return (v3);
}
