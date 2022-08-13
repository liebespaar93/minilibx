/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:42:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/08 18:39:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_screan.h>
#include <stdlib.h>

t_screan	*ft_new_screan(t_vec2 v2_1, t_vec2 v2_2, t_vec3 v_origin)
{
	t_screan	*new;

	new = (t_screan *)malloc(sizeof(t_screan));
	if (!new)
		return (NULL);
	new->axis_1 = v2_1;
	new->axis_2 = v2_2;
	new->origin = v_origin;
	return (new);
}

t_screan	*ft_screan_init(void)
{
	t_vec2	v2_1;
	t_vec2	v2_2;
	t_vec3	v3_origin;

	v2_1 = ft_vector_2(1, 0);
	v2_2 = ft_vector_2(0, 1);
	v3_origin = ft_vector_3(0, 0, 0);
	return (ft_new_screan(v2_1, v2_2, v3_origin));
}

t_screan	*ft_screan_set(t_screan *screan, t_vec2 v2_1, t_vec2 v2_2, \
	t_vec3 v_origin)
{
	screan->axis_1 = v2_1;
	screan->axis_2 = v2_2;
	screan->origin = v_origin;
	return (screan);
}

t_vec2	ft_screan_transform(t_screan *screan, t_vec2 v2)
{
	v2 = ft_vec2_sum(\
		ft_vec2_mult(screan->axis_1, v2.x), \
		ft_vec2_mult(screan->axis_2, v2.y) \
		);
	v2.x = screan->origin.x;
	v2.y = screan->origin.y;
	return (v2);
}
