/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:43:57 by obahi             #+#    #+#             */
/*   Updated: 2023/04/09 08:29:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *a)
{
	if (a->t[1] < a->t[0] && a->t[0] < a->t[2])
		return (ft_swap(a, 1));
	if (a->t[2] < a->t[1] && a->t[1] < a->t[0])
		return (ft_swap(a, 1), ft_rrotate(a, 1));
	if (a->t[1] < a->t[2] && a->t[2] < a->t[0])
		return (ft_rotate(a, 1));
	if (a->t[0] < a->t[2] && a->t[2] < a->t[1])
		return (ft_swap(a, 1), ft_rotate(a, 1));
	if (a->t[2] < a->t[0] && a->t[0] < a->t[1])
		return (ft_rrotate(a, 1));
}

int	ft_nb_moves(t_moves m)
{
	m.rr = min(m.ra, m.rb);
	m.rrr = min(m.rra, m.rrb);
	m.ra -= m.rr;
	m.rb -= m.rr;
	m.rra -= m.rrr;
	m.rrb -= m.rrr;
	return (m.ra + m.rb + m.rr + m.rra + m.rrb + m.rrr);
}

t_moves	ft_moves(t_stack a, t_stack b, int i)
{
	t_moves	m;
	int		j;

	m.ra = 0;
	m.rb = 0;
	m.rr = 0;
	m.rra = 0;
	m.rrb = 0;
	m.rrr = 0;
	j = ft_index(a, b, i);
	if (i <= b.n / 2)
		m.rb = i;
	else
		m.rrb = b.n - i;
	if (j <= a.n / 2)
		m.ra = j;
	else
		m.rra = a.n - j;
	return (m);
}

void	ft_move_it(t_stack *a, t_stack *b, t_moves m)
{
	m.rr = min(m.ra, m.rb);
	m.rrr = min(m.rra, m.rrb);
	m.ra -= m.rr;
	m.rb -= m.rr;
	m.rra -= m.rrr;
	m.rrb -= m.rrr;
	while (m.ra--)
		ft_rotate(a, 1);
	while (m.rb--)
		ft_rotate(b, 1);
	while (m.rr--)
		ft_rotate_2(a, b, 1);
	while (m.rra--)
		ft_rrotate(a, 1);
	while (m.rrb--)
		ft_rrotate(b, 1);
	while (m.rrr--)
		ft_rrotate_2(a, b, 1);
	ft_push(b, a, 1);
}

t_moves	ft_best_move(t_stack a, t_stack b)
{
	t_moves	m;
	t_moves	m1;
	int		k;
	int		k1;
	int		i;

	m = ft_moves(a, b, 0);
	k = ft_nb_moves(m);
	i = 1;
	while (i < b.n)
	{
		m1 = ft_moves(a, b, i);
		k1 = ft_nb_moves(m1);
		if (k1 <= k)
		{
			m = ft_moves(a, b, i);
			k = k1;
		}
		i++;
	}
	return (m);
}
