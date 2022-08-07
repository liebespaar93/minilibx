/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:41:15 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 17:41:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

t_vec2	ft_vector_2(float x, float y)
{
	t_vec2	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_vec2	ft_vec2_sum(t_vec2 v2_1, t_vec2 v2_2)
{
	v2_1.x += v2_2.x;
	v2_1.y += v2_2.y;
	return (v2_1);
}

t_vec2	ft_vec2_mult(t_vec2 v2, float scalar)
{
	v2.x *= scalar;
	v2.y *= scalar;
	return (v2);
}
