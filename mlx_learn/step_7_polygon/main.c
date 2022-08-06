/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:16:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 23:45:39 by kyoulee          ###   ########.fr       */
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

void	ft_draw2_line(t_param *param)
{
	t_vec2		v0;

	v0 = ft_vector_2(2, 1);
	ft_draw_basis2_grid(param, 20, 20, 0x00336600);
	ft_draw_basis2_axis(param, 20, 20, 0x00669900);
	ft_draw_line(param, v0, ft_vector_2(4, 2), 0x00FFCC66);
}

void	ft_draw_mtx3_transform(t_param *param)
{
	t_vec2		v0;
	t_vec2		v1;
	t_mtx3		m3_rotation;
	t_mtx3		m3_translation;

	v0 = ft_vector_2(0, 0);
	v1 = ft_vector_2(2, 1);
	m3_rotation = ft_mtx3_rotation(C_PI * param->mouse->x_angle / 180);
	m3_translation = ft_mtx3_translation(2, 1);
	ft_draw_line(param, \
		ft_mtx3_mult_vec2(m3_translation, ft_mtx3_mult_vec2(m3_rotation, v0)),
		ft_mtx3_mult_vec2(m3_translation, ft_mtx3_mult_vec2(m3_rotation, v1)),
		0x00FF0099
		);
	param->screan->origin.x += 3;
	ft_draw_line(param, \
		ft_mtx3_mult_vec2(ft_mtx3_mult_mtx3(m3_translation, m3_rotation), v0),
		ft_mtx3_mult_vec2(ft_mtx3_mult_mtx3(m3_translation, m3_rotation), v1),
		0x00CC33
		);
	param->screan->origin.x -= 3;
}

void	ft_draw_mtx3_transform_wrong(t_param *param)
{
	t_vec2		v0;
	t_vec2		v1;
	t_mtx3		m3_rotation;
	t_mtx3		m3_translation;

	v0 = ft_vector_2(0, 0);
	v1 = ft_vector_2(2, 1);
	m3_rotation = ft_mtx3_rotation(C_PI * param->mouse->x_angle / 180);
	m3_translation = ft_mtx3_translation(2, 1);
	ft_draw_line(param, \
		ft_mtx3_mult_vec2(m3_rotation, ft_mtx3_mult_vec2(m3_translation, v0)),
		ft_mtx3_mult_vec2(m3_rotation, ft_mtx3_mult_vec2(m3_translation, v1)),
		0x00FF00FF
		);
	ft_draw_line(param, \
		ft_vec2_mult_mtx3(ft_vec2_mult_mtx3(v0, m3_rotation), m3_translation),
		ft_vec2_mult_mtx3(ft_vec2_mult_mtx3(v1, m3_rotation), m3_translation),
		0x003333FF
		);
	ft_draw_line(param, \
		ft_vec2_mult_mtx3(ft_vec2_mult_mtx3(v0, m3_translation), m3_rotation),
		ft_vec2_mult_mtx3(ft_vec2_mult_mtx3(v1, m3_translation), m3_rotation),
		0x0000FFFF
		);
}

int	ft_loop_event(t_param *param)
{
	ft_key_update(param->screan, param->keyboard);
	ft_mouse_update(param->screan, param->mouse);
	ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
	ft_draw2_line(param);
	ft_draw_mtx3_transform(param);
	ft_draw_mtx3_transform_wrong(param);
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
