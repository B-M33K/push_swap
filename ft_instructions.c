/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:21:33 by obahi             #+#    #+#             */
/*   Updated: 2023/03/23 10:31:48 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack *s)
{
	int	tmp;

	if (s->n >= 2)
	{
		tmp = s->t[0];
		s->t[0] = s->t[1];
		s->t[1] = tmp;
		write(1, "s", 1);
		write(1, &s->c, 1);
		write(1, "\n", 1);
	}
}

void	ft_swap_2(t_stack *s1, t_stack *s2)
{
	int	tmp;

	if (s1->n >= 2)
	{
		tmp = s1->t[0];
		s1->t[0] = s1->t[1];
		s1->t[1] = tmp;
	}
	if (s2->n >= 2)
	{
		tmp = s2->t[0];
		s2->t[0] = s2->t[1];
		s2->t[1] = tmp;
	}
	write(1, "ss\n", 3);
}

void	ft_rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->n >= 2)
	{
		tmp = s->t[0];
		i = -1;
		while(++i < s->n - 1)
			s->t[i] = s->t[i+1];
		s->t[i] = tmp;
		write(1, "r", 1);
		write(1, &s->c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate_2(t_stack *s1, t_stack *s2)
{
	int	tmp;
	int	i;

	if (s1->n >= 2)
	{
		tmp = s1->t[0];
		i = -1;
		while(++i < s1->n - 1)
			s1->t[i] = s1->t[i+1];
		s1->t[i] = tmp;
	}
	if (s2->n >= 2)
	{
		tmp = s2->t[0];
		i = -1;
		while(++i < s2->n - 1)
			s2->t[i] = s2->t[i+1];
		s2->t[i] = tmp;
	}
	write(1, "rr\n", 3);
}

void	ft_rrotate(t_stack *s)
{
	int	tmp;
	int i;

	i = s->n;
	tmp = s->t[i-1];
	while (--i > 0)
		s->t[i] = s->t[i-1];
	s->t[i] = tmp;
	write(1, "rr", 2);
	write(1, &s->c, 1);
	write(1, "\n", 1);
}

void	ft_rrotate_2(t_stack *s1, t_stack *s2)
{
	int	tmp;
	int i;

	i = s1->n;
	tmp = s1->t[i-1];
	while (--i > 0)
		s1->t[i] = s1->t[i-1];
	i = s2->n;
	tmp = s2->t[i-1];
	while (--i > 0)
		s2->t[i] = s2->t[i-1];
	write(1, "rrr", 2);	
}

void	ft_push(t_stack *src, t_stack *dst)
{
	int	i;

	i = dst->n;
	while (--i >= 0)
		dst->t[i + 1] = dst->t[i];
	dst->t[0] = src->t[0];
	dst->n++;
	i = -1;
	while (++i < src->n - 1)
		src->t[i] = src->t[i + 1];
	src->n--;
	write(1, "p", 1);
	write(1, &dst->c, 1);
	write(1, "\n", 1);
}