/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:47:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 00:21:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_src.h>

double	ft_min(double value1, double value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}

double	ft_max(double value1, double value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
}

double	ft_cycle(double value, double cycle)
{
	double	abs_cycle;

	abs_cycle = ft_abs(cycle);
	while (value < -abs_cycle)
		value += abs_cycle * 2;
	while (value > abs_cycle)
		value -= abs_cycle * 2;
	return (value);
}
