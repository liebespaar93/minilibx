/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:16:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 18:32:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <ft_draw.h>
#include <mlx.h>
#include <ft_src.h>

int	main(void)
{
	t_param		*param;
	t_vec2		v0;

	param = ft_param_init();
	ft_screan_set(param->screan, \
		ft_vector_2(10, 0), ft_vector_2(0, -10), param->screan->origin);
	if (1)
		ft_basis2_set(param->basis2, ft_vector_2(4, 2), ft_vector_2(1, 3));
	ft_draw_basis2_grid(param, 20, 20, 0xC0FFFFFF);
	ft_draw_basis2_axis(param, 20, 20, 0x00FFFFFF);
	v0 = ft_vector_2(0, 0);
	ft_draw_line(param, v0, ft_vector_2(10, 10), 0x0000FF00);
	ft_draw_line(param, v0, ft_vector_2(-10, 10), 0x0000FF00);
	ft_draw_line(param, v0, ft_vector_2(-10, -10), 0x0000FF00);
	ft_draw_line(param, v0, ft_vector_2(10, -10), 0x0000FF00);
	ft_memcpy(param->buffer, param->back_buffer, \
		param->size_line * CANVAS_HEIGHT);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
		param->img_ptr, CANVAS_X, CANVAS_Y);
	mlx_loop(param->mlx_ptr);
	ft_param_free(&param);
	return (1);
}
