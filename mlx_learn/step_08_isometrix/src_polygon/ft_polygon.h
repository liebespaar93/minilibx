/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polygon.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:24:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/07 21:30:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POLYGON_H
# define FT_POLYGON_H

# include <ft_vector.h>
# include <ft_matrix.h>

typedef struct s_primitive	t_prim;
typedef struct s_polygon	t_ply;

typedef struct s_primitive
{
	int	p1;
	int	p2;
	int	p3;
}	t_prim;

typedef struct s_polygon
{
	t_prim	*prim_buff;
	int		size_prim;
	t_vec3	*v3_buff;
	int		size_v3;
}	t_ply;

/* ft_ploygon */
t_ply	*ft_ply_free(t_ply **ply_ptr);
t_ply	*ft_ply_set_primbuffer(t_ply *ply, t_prim *buffer, int index);
t_ply	*ft_ply_set_vbuffer(t_ply *ply, t_vec3 *buffer, int index);
t_ply	*ft_polygon_init(void);
t_ply	*ft_polygon_transform(t_ply *ply, t_mtx4 m4);

/* ft_primitive */
t_prim	ft_primitive(int p1, int p2, int p3);

#endif