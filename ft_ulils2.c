/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:40:18 by obahi             #+#    #+#             */
/*   Updated: 2023/04/05 22:40:57 by obahi            ###   ########.fr       */
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

	j = ft_index(a, b, i);
	if (i <= b.n / 2)
		m.rb = i;
	else
		m.rrb = b.n - i;
	if (j <= a.n / 2)
		m.ra = j;
	else
		m.rra = a.n - i;
	return m;
}

void	ft_move_it(t_stack *a, t_stack *b, t_moves m)
{
	int	i;

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