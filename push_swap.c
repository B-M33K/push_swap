/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:49:27 by obahi             #+#    #+#             */
/*   Updated: 2023/04/08 00:22:08 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	t_moves m1;
	int		min;
	int		max;

	i = -1;
	a = ft_stack(argc - 1, 'a');
	b = ft_stack(argc - 1, 'b');
	while (++i < argc - 1)
	{
		a.t[i] = ft_atoi(*(argv + 1 + i));
		a.n++;
	}
	min = a.t[ft_min(a)];
	max = a.t[ft_max(a)];
	while (a.n > 3)
	{
		if (a.t[0] == min || a.t[0] == max)
			ft_rotate(&a);
		else
			ft_push(&a, &b);
	}
	ft_sort_3(&a);
	while (b.n > 0)
	{
		m1 = ft_best_move(a, b);
		ft_move_it(&a, &b, m1);
	}
	i = ft_min(a);
	if (i <= a.n / 2)
		while(i--)
			ft_rotate(&a);
	else
	{
		i = a.n - i;
		while(i--)
			ft_rrotate(&a);
	}
	return (0);
}