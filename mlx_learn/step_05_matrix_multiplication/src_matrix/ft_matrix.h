/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:51:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 08:55:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include <ft_vector.h>

typedef struct s_matrix2	t_mtx2;

typedef struct s_matrix2
{
	float	m11;
	float	m12;
	float	m21;
	float	m22;
}	t_mtx2;

t_mtx2	ft_matrix_2(float m11, float m12, float m21, float m22);
t_vec2	ft_mtx2_mult_vec2(t_mtx2 m2, t_vec2 v2);
t_vec2	ft_vec2_mult_mtx2(t_vec2 v2, t_mtx2 m2);
t_mtx2	ft_mtx2_mult_scalar(t_mtx2 m2, float scalar);
t_mtx2	ft_mtx2_rotation(float angle);
t_mtx2	ft_mtx2_mult_mtx2(t_mtx2 m2_1, t_mtx2 m2_2);
t_mtx2	ft_mtx2_shear(float x, float y);

#endif