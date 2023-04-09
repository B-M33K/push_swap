/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:40:39 by obahi             #+#    #+#             */
/*   Updated: 2023/04/09 08:31:56 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack *s, int p)
{
	int	tmp;

	if (s->n < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	tmp = s->t[0];
	s->t[0] = s->t[1];
	s->t[1] = tmp;
	if (p)
	{
		write(1, "s", 1);
		write(1, &s->c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate(t_stack *s, int p)
{
	int	tmp;
	int	i;

	if (s->n < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	tmp = s->t[0];
	i = -1;
	while (++i < s->n - 1)
		s->t[i] = s->t[i + 1];
	s->t[i] = tmp;
	if (p)
	{
		write(1, "r", 1);
		write(1, &s->c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rrotate(t_stack *s, int p)
{
	int	tmp;
	int	i;

	if (s->n < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	i = s->n;
	tmp = s->t[i - 1];
	while (--i > 0)
		s->t[i] = s->t[i - 1];
	s->t[i] = tmp;
	if (p)
	{
		write(1, "rr", 2);
		write(1, &s->c, 1);
		write(1, "\n", 1);
	}
}

void	ft_push(t_stack *src, t_stack *dst, int p)
{
	int	i;

	if (src->n == 0)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	i = dst->n;
	while (--i >= 0)
		dst->t[i + 1] = dst->t[i];
	dst->t[0] = src->t[0];
	dst->n++;
	i = -1;
	while (++i < src->n - 1)
		src->t[i] = src->t[i + 1];
	src->n--;
	if (p)
	{
		write(1, "p", 1);
		write(1, &dst->c, 1);
		write(1, "\n", 1);
	}
}
