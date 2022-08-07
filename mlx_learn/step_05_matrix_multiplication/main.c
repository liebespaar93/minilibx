/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:16:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 16:32:19 by kyoulee          ###   ########.fr       */
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

	v0 = ft_vector_2(0, 0);
	ft_draw_basis2_grid(param, 20, 20, 0x00336600);
	ft_draw_basis2_axis(param, 20, 20, 0x00669900);
	ft_draw_line(param, v0, ft_vector_2(2, 3), 0x00FFCC66);
}

void	ft_draw_transform(t_param *param)
{
	t_vec2		v0;
	t_mtx2		m2_rotation;
	t_mtx2		m2_shear;
	t_mtx2		m2;
	int			rgb;

	v0 = ft_vector_2(0, 0);
	m2_rotation = ft_mtx2_rotation(C_PI * param->mouse->x_angle / 180);
	m2_shear = ft_mtx2_shear(0, 1);
	m2 = ft_mtx2_mult_mtx2(m2_shear, m2_rotation);
	rgb = 0x00FFFFFF;
	param->screan->origin.x--;
	ft_draw_line(param, v0, ft_mtx2_mult_vec2(m2, ft_vector_2(2, 3)), rgb);
	param->screan->origin.x++;
	ft_basis2_set(param->basis2, ft_vector_2(1, 0), ft_vector_2(1, 1));
	ft_draw_basis2_grid(param, 20, 20, 0x00336666);
	ft_draw_basis2_axis(param, 20, 20, 0x00669999);
	ft_basis2_set(param->basis2, ft_vector_2(1, 0), ft_vector_2(0, 1));
}

int	ft_loop_event(t_param *param)
{
	ft_key_update(param->screan, param->keyboard);
	ft_mouse_update(param->screan, param->mouse);
	ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
	ft_draw2_line(param);
	ft_draw_transform(param);
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
