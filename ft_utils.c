/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 07:20:10 by obahi             #+#    #+#             */
/*   Updated: 2023/04/06 10:37:00 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_min(t_stack s)
{
	int	min;
	int	i;

	min = 0;
	i = 0;
	while (++i < s.n)
		if (s.t[i] < s.t[min])
			min = i;
	return (min);
}

int	ft_max(t_stack s)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (++i < s.n)
		if (s.t[i] > s.t[max])
			max = i;
	return (max);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_index(t_stack a, t_stack b, int i)
{
	int	j;

	j = -1;
	while (++j < a.n - 1)
		if (b.t[i] > a.t[j] && b.t[i] < a.t[j + 1])
			return (j + 1);
	return (0);
}
