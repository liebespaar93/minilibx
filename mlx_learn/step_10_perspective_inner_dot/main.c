/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:16:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/08 12:15:26 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <ft_draw.h>
#include <mlx.h>
#include <ft_src.h>
#include <ft_mac_mouse.h>
#include <ft_mac_keyboard.h>
#include <ft_loop.h>
#include <ft_matrix.h>
#include <ft_polygon.h>

void	ft_make_buffers(t_prim **prim_buff_ptr, t_vec3 **v3_buff_ptr)
{
	t_prim	*prim_buff;
	t_vec3	*v3_buff;

	if (!ft_zeromalloc((void **)&prim_buff, sizeof(t_prim) * 12))
		return ;
	if (!ft_zeromalloc((void **)&v3_buff, sizeof(t_prim) * 8))
		return ;
	ft_prim_cube(&prim_buff, (int [8]){0, 1, 2, 3, 4, 5, 6, 7});
	v3_buff[0] = ft_vector_3(0, 0, 1);
	v3_buff[1] = ft_vector_3(1, 0, 1);
	v3_buff[2] = ft_vector_3(0, 1, 1);
	v3_buff[3] = ft_vector_3(1, 1, 1);
	v3_buff[4] = ft_vector_3(0, 0, 2);
	v3_buff[5] = ft_vector_3(1, 0, 2);
	v3_buff[6] = ft_vector_3(0, 1, 2);
	v3_buff[7] = ft_vector_3(1, 1, 2);
	*prim_buff_ptr = prim_buff;
	*v3_buff_ptr = v3_buff;
}

void	ft_draw_prim(t_param *param, t_ply *ply, t_prim prim)
{
	t_vec3	normal;
	int		color;
	t_vec3 c1;
	t_vec3 c2;
	t_vec3 c3;
	t_vec3 c4;

	c1 = ply->v3_buff[prim.p1];
	c2 = ply->v3_buff[prim.p2];
	c3 = ply->v3_buff[prim.p3];
	normal = ft_vec3_cross(\
	ft_vec3_minus(ply->v3_buff[prim.p2], ply->v3_buff[prim.p1]), \
	ft_vec3_minus(ply->v3_buff[prim.p3], ply->v3_buff[prim.p1])
	);
	normal = ft_vec3_normalize(normal);
	color = 0x00FFCC66;
	float test =ft_vec3_dot(ft_vector_3(0,0,1), normal);
	if (ft_vec3_dot(ft_vector_3(0,0,1), normal) > 0)
		color = 0x00FF0000;
	ft_draw_line(param, \
	ft_vector_2(ply->v3_buff[prim.p1].x, ply->v3_buff[prim.p1].y), \
	ft_vector_2(ply->v3_buff[prim.p2].x, ply->v3_buff[prim.p2].y), \
	color);
	ft_draw_line(param, \
	ft_vector_2(ply->v3_buff[prim.p2].x, ply->v3_buff[prim.p2].y), \
	ft_vector_2(ply->v3_buff[prim.p3].x, ply->v3_buff[prim.p3].y), \
	color);
	ft_draw_line(param, \
	ft_vector_2(ply->v3_buff[prim.p3].x, ply->v3_buff[prim.p3].y), \
	ft_vector_2(ply->v3_buff[prim.p1].x, ply->v3_buff[prim.p1].y), \
	0x00FFCC66);
}

void	ft_draw_ply(t_param *param, t_prim	*prim_buff, t_vec3	*v3_buff)
{
	t_ply	*ply;
	t_mtx4	m4_rot_x;
	t_mtx4	m4_rot_y;
	t_mtx4	m4_tranform;
	int		i;

	ft_draw_basis2_grid(param, 20, 20, 0x00336600);
	ft_draw_basis2_axis(param, 20, 20, 0x00669900);
	ply = ft_polygon_init();
	if (!prim_buff || !v3_buff)
		ft_make_buffers(&prim_buff, &v3_buff);
	ft_ply_set_primbuffer(ply, prim_buff, 12);
	ft_ply_set_vbuffer(ply, v3_buff, 8);
	m4_tranform = ft_mtx4_translation(0, 0, 0);
	m4_rot_x = ft_mtx4_rot_x(C_PI * param->mouse->y_angle / 180);
	m4_rot_y = ft_mtx4_rot_y(C_PI * param->mouse->x_angle / 180);
	m4_tranform = \
		ft_mtx4_mult_mtx4(ft_mtx4_mult_mtx4(m4_tranform, m4_rot_y), m4_rot_x);
	ply = ft_polygon_transform(ply, m4_tranform);
	ply = ft_polygon_transform(ply, ft_mtx4_projection(5));
	i = -1;
	while (++i < ply->size_prim)
		ft_draw_prim(param, ply, ply->prim_buff[i]);
}

int	ft_loop_event(t_param *param)
{
	ft_key_update(param->screan, param->keyboard);
	ft_mouse_update(param->screan, param->mouse);
	ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
	ft_draw_ply(param, 0, 0);
	ft_memcpy(param->buffer, param->back_buffer, \
		param->size_line * CANVAS_HEIGHT);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
		param->img_ptr, CANVAS_X, CANVAS_Y);
	return (0);
}

int	main(void)
{
	t_param		*param;

	param = ft_param_init();
	ft_screan_set(param->screan, \
		ft_vector_2(10, 0), ft_vector_2(0, 10), param->screan->origin);
	ft_mlx_key_mouse_set(param);
	if (1)
		ft_basis2_set(param->basis2, ft_vector_2(1, 0), ft_vector_2(0, 1));
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx_ptr);
	ft_param_free(&param);
	return (1);
}
