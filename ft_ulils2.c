/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:40:18 by obahi             #+#    #+#             */
/*   Updated: 2023/04/08 00:01:13 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *a)
{
	if (a->t[0] > a->t[1] && a->t[0] < a->t[2])
		return (ft_swap(a));
	if (a->t[0] > a->t[1] && a->t[1] > a->t[2])
		return (ft_swap(a), ft_rrotate(a));
	if (a->t[0] > a->t[1] && a->t[1] < a->t[2])
		return (ft_rotate(a));
	if (a->t[0] < a->t[1] && a->t[0] < a->t[2])
		return (ft_swap(a), ft_rotate(a));
	if (a->t[0] < a->t[1] && a->t[0] > a->t[2])
		return (ft_rrotate(a));
}

void ft_print_moves(t_moves m)
{
	printf("MOVES\n");
	printf("ra == %d\n",m.ra);
	printf("rb == %d\n",m.rb);
	printf("rr == %d\n",m.rr);
	printf("rra == %d\n",m.rra);
	printf("rrb == %d\n",m.rrb);
	printf("rrr == %d\n",m.rrr);
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
	t_moves m;
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
	return m;
}

void	ft_move_it(t_stack *a, t_stack *b, t_moves m)
{
	int	i;
	m.rr = min(m.ra, m.rb);
	m.rrr = min(m.rra, m.rrb);
	m.ra -= m.rr;
	m.rb -= m.rr;
	m.rra -= m.rrr;
	m.rrb -= m.rrr;
	i = -1;
	while (++i < m.ra)
		ft_rotate(a);
	i = -1;
	while (++i < m.rb)
		ft_rotate(b);
	i = -1;
	while (++i < m.rr)
		ft_rotate_2(a, b);
	i = -1;
	while (++i < m.rra)
		ft_rrotate(a);
	i = -1;
	while (++i < m.rrb)
		ft_rrotate(b);
	i = -1;
	while (++i < m.rrr)
		ft_rrotate_2(a, b);
	ft_push(b, a);
}

t_moves	ft_best_move(t_stack a, t_stack b)
{
	t_moves m;
	t_moves m1;
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

void	ft_print_array(int *t, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("t[%d] == %d\n",i, t[i]);
		i++;
	}
}