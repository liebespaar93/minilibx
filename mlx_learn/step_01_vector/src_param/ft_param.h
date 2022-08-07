/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:45:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 17:46:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAM_H
# define FT_PARAM_H

# define WIN_WIDTH   1000
# define WIN_HEIGHT  700

# define CANVAS_X		0
# define CANVAS_Y		0
# define CANVAS_WIDTH	WIN_WIDTH
# define CANVAS_HEIGHT	WIN_HEIGHT

# include <ft_basis.h>
# include <ft_screan.h>

typedef struct s_param	t_param;

typedef struct s_param
{
	void		*mlx_ptr;
	void		*win_ptr;

	t_screan	*screan;
	t_basis2	*basis2;
}	t_param;

t_param	*ft_param_free(t_param **param_ptr);
t_param	*ft_param_init(void);
#endif