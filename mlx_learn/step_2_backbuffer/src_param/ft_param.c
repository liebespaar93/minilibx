/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:46:47 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 18:31:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <stdlib.h>
#include <mlx.h>

t_param	*ft_param_free(t_param **param_ptr)
{
	t_param	*param;

	param = *param_ptr;
	if (param)
	{
		if (param->mlx_ptr)
			free(param->mlx_ptr);
		if (param->win_ptr)
			free(param->win_ptr);
		if (param->screan)
			free(param->screan);
		if (param->basis2)
			free(param->basis2);
		free(param);
	}
	*param_ptr = NULL;
	return (*param_ptr);
}

t_param	*ft_param_init(void)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
		"mlx_learn step 2 by kyoulee");
	param->img_ptr = mlx_new_image(param->mlx_ptr, CANVAS_WIDTH, CANVAS_HEIGHT);
	param->buffer = mlx_get_data_addr(param->img_ptr, &param->bits_per_pixel, \
			&param->size_line, &param->endian);
	param->back_buffer = malloc(param->size_line * CANVAS_HEIGHT);
	if (!param->back_buffer)
		return (ft_param_free(&param));
	param->screan = ft_screan_init();
	if (!param->screan)
		return (ft_param_free(&param));
	param->screan->origin.x = CANVAS_X + CANVAS_WIDTH / 2;
	param->screan->origin.y = CANVAS_Y + CANVAS_HEIGHT / 2;
	param->basis2 = ft_basis2_init();
	if (!param->basis2)
		return (ft_param_free(&param));
	return (param);
}
