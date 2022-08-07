/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constant_root.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:10:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/11 19:10:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 
	루트 만드는 함수 약 21번 이상을 돌리는 것을 추천한다.
	반복 횟수는 홀수로 하여 높은 수를 얻으는 것을 추천한다.
	반복될수록 좀더 상세하게 루트의 값을 찾층수 있다.
	#define C_SQUARE_ROOT_2 1.41421356237309504880168872420969807
	#define C_SQUARE_ROOT_3 1.73205080756887729352744634150587236
	#define C_SQUARE_ROOT_5 2.23606797749978969640917366873127623
	공식 :: https://en.wikipedia.org/wiki/Square_root
*/
/* ************************************************************************** */

double	ft_constant_square_root(int integer, int repeat)
{
	double	root;
	double	num;

	root = 0.5;
	num = 0;
	while (num < repeat)
	{
		root = 1 + ((integer - 1) / (1 + root));
		num++;
	}
	return (root);
}

double	ft_sqrt(float integer)
{
	double	root;
	double	num;

	root = 0.5;
	num = 0;
	while (num < 21)
	{
		root = 1 + ((integer - 1) / (1 + root));
		num++;
	}
	return (root);
}
