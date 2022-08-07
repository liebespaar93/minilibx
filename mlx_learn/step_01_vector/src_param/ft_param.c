/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:46:47 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 17:46:56 by kyoulee          ###   ########.fr       */
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
		"mlx_learn step 1 by kyoulee");
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
