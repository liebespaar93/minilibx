/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:51:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 23:45:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include <ft_vector.h>

typedef struct s_matrix2	t_mtx2;
typedef struct s_matrix3	t_mtx3;

typedef struct s_matrix2
{
	float	m11;
	float	m12;
	float	m21;
	float	m22;
}	t_mtx2;

typedef struct s_matrix3
{
	float	m11;
	float	m12;
	float	m13;
	float	m21;
	float	m22;
	float	m23;
	float	m31;
	float	m32;
	float	m33;
}	t_mtx3;

/* ft_matrix_2 */
t_mtx2	ft_matrix_2(float m11, float m12, float m21, float m22);
t_mtx2	ft_mtx2_identity(void);
t_mtx2	ft_mtx2_shear(float x, float y);
t_mtx2	ft_mtx2_rotation(float angle);

t_mtx2	ft_mtx2_mult_scalar(t_mtx2 m2, float scalar);
t_vec2	ft_vec2_mult_mtx2(t_vec2 v2, t_mtx2 m2);
t_vec2	ft_mtx2_mult_vec2(t_mtx2 m2, t_vec2 v2);
t_mtx2	ft_mtx2_mult_mtx2(t_mtx2 m2_1, t_mtx2 m2_2);

/* ft_matrix_3 */
t_mtx3	ft_matrix_3(float *m1, float *m2, float *m3);
t_mtx3	ft_mtx3_identity(void);
t_mtx3	ft_mtx3_translation(float x, float y);
t_mtx3	ft_mtx3_shear(float x, float y);
t_mtx3	ft_mtx3_rotation(float angle);

t_mtx3	ft_mtx3_mult_scalar(t_mtx3 m3, float scalar);
t_vec2	ft_vec2_mult_mtx3(t_vec2 v2, t_mtx3 m3);
t_vec2	ft_mtx3_mult_vec2(t_mtx3 m3, t_vec2 v2);
t_mtx3	ft_mtx3_mult_mtx3(t_mtx3 m3_1, t_mtx3 m3_2);
#endif