/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:16:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 22:22:13 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <ft_draw.h>
#include <mlx.h>
#include <ft_src.h>
#include <ft_mac_mouse.h>
#include <ft_mac_keyboard.h>
#include <ft_loop.h>

void	ft_draw4_line(t_param *param)
{
	t_vec2		v0;

	v0 = ft_vector_2(0, 0);
	ft_draw_basis2_grid(param, 20, 20, 0xC0FFFFFF);
	ft_draw_basis2_axis(param, 20, 20, 0x00FFFFFF);
	ft_draw_line(param, v0, ft_vector_2(10, 10), 0x0000FF00);
	ft_draw_line(param, v0, ft_vector_2(-10, 10), 0x0000FF00);
	ft_draw_line(param, v0, ft_vector_2(-10, -10), 0x0000FF00);
	ft_draw_line(param, v0, ft_vector_2(10, -10), 0x0000FF00);
	ft_memcpy(param->buffer, param->back_buffer, \
		param->size_line * CANVAS_HEIGHT);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
		param->img_ptr, CANVAS_X, CANVAS_Y);
}

int	ft_loop_event(t_param *param)
{
	ft_key_update(param->screan, param->keyboard);
	ft_mouse_update(param->screan, param->mouse);
	ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
	ft_draw4_line(param);
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
		ft_basis2_set(param->basis2, ft_vector_2(4, 2), ft_vector_2(1, 3));
	ft_draw4_line(param);
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx_ptr);
	ft_param_free(&param);
	return (1);
}
