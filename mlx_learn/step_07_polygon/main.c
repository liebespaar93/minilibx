/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:16:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/07 02:53:38 by kyoulee          ###   ########.fr       */
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

void	ft_draw2_line(t_param *param)
{
	ft_draw_basis2_grid(param, 20, 20, 0x00336600);
	ft_draw_basis2_axis(param, 20, 20, 0x00669900);
}

void	ft_make_buffers(t_prim **prim_buff_ptr, t_vec3 **v3_buff_ptr)
{
	t_prim	*prim_buff;
	t_vec3	*v3_buff;

	if (!ft_zeromalloc((void **)&prim_buff, sizeof(t_prim) * 2))
		return ;
	if (!ft_zeromalloc((void **)&v3_buff, sizeof(t_prim) * 4))
		return ;
	prim_buff[0] = ft_primitive(0, 1, 2);
	prim_buff[1] = ft_primitive(1, 2, 3);
	v3_buff[0] = ft_vector_3(-5, -5, 0);
	v3_buff[1] = ft_vector_3(5, -5, 0);
	v3_buff[2] = ft_vector_3(-5, 5, 0);
	v3_buff[3] = ft_vector_3(5, 5, 0);
	*prim_buff_ptr = prim_buff;
	*v3_buff_ptr = v3_buff;
}

void	ft_draw_ply(t_param *param, t_prim	*prim_buff, t_vec3	*v3_buff)
{
	t_ply	*ply;
	t_prim	prim;
	int		i;

	ply = ft_polygon_init();
	ft_make_buffers(&prim_buff, &v3_buff);
	ft_ply_set_primbuffer(ply, prim_buff, 2);
	ft_ply_set_vbuffer(ply, v3_buff, 4);
	i = -1;
	while (++i < ply->size_prim)
	{
		prim = ply->prim_buff[i];
		ft_draw_line(param, \
		ft_vector_2(ply->v3_buff[prim.p1].x, ply->v3_buff[prim.p1].y), \
		ft_vector_2(ply->v3_buff[prim.p2].x, ply->v3_buff[prim.p2].y), \
		0x00FFCC66);
		ft_draw_line(param, \
		ft_vector_2(ply->v3_buff[prim.p2].x, ply->v3_buff[prim.p2].y), \
		ft_vector_2(ply->v3_buff[prim.p3].x, ply->v3_buff[prim.p3].y), \
		0x00FFCC66);
		ft_draw_line(param, \
		ft_vector_2(ply->v3_buff[prim.p3].x, ply->v3_buff[prim.p3].y), \
		ft_vector_2(ply->v3_buff[prim.p1].x, ply->v3_buff[prim.p1].y), \
		0x00FFCC66);
	}
}

int	ft_loop_event(t_param *param)
{
	ft_key_update(param->screan, param->keyboard);
	ft_mouse_update(param->screan, param->mouse);
	ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
	ft_draw2_line(param);
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
		ft_vector_2(10, 0), ft_vector_2(0, -10), param->screan->origin);
	ft_mlx_key_mouse_set(param);
	if (1)
		ft_basis2_set(param->basis2, ft_vector_2(1, 0), ft_vector_2(0, 1));
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx_ptr);
	ft_param_free(&param);
	return (1);
}
