/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:27:25 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 17:29:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_H
# define FT_DRAW_H

# include <ft_param.h>

void	ft_draw_line(t_param *param, t_vec2 v2_1, t_vec2 v2_2, int color);
void	ft_draw_basis2_axis(t_param *param, int x, int y, int color);
void	ft_draw_basis2_grid(t_param *param, int x, int y, int color);
void	ft_scanline_x(t_vec2 standard, t_vec2 next, t_param *param, int color);
void	ft_scanline_y(t_vec2 standard, t_vec2 next, t_param *param, int color);
void	ft_scanline(t_vec2 standard, t_vec2 next, t_param *param, int color);
#endif
