/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:41:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 08:37:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct s_vector_2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vector_3
{
	float	x;
	float	y;
	float	z;
}	t_vec_3;

t_vec2	ft_vector_2(float x, float y);
t_vec2	ft_vec2_sum(t_vec2 v2_1, t_vec2 v2_2);
t_vec2	ft_vec2_mult(t_vec2 v2, float scalar);
float	ft_vec2_length(t_vec2 v2);

#endif