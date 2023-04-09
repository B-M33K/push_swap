/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:40:35 by obahi             #+#    #+#             */
/*   Updated: 2023/04/09 08:26:45 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_2(t_stack *s1, t_stack *s2, int p)
{
	int	tmp;

	if (s1->n < 2 || s2->n < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	tmp = s1->t[0];
	s1->t[0] = s1->t[1];
	s1->t[1] = tmp;
	tmp = s2->t[0];
	s2->t[0] = s2->t[1];
	s2->t[1] = tmp;
	if (p)
		write(1, "ss\n", 3);
}

void	ft_rotate_2(t_stack *s1, t_stack *s2, int p)
{
	int	tmp;
	int	i;

	if (s1->n < 2 || s2->n < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	tmp = s1->t[0];
	i = -1;
	while (++i < s1->n - 1)
		s1->t[i] = s1->t[i + 1];
	s1->t[i] = tmp;
	tmp = s2->t[0];
	i = -1;
	while (++i < s2->n - 1)
		s2->t[i] = s2->t[i + 1];
	s2->t[i] = tmp;
	if (p)
		write(1, "rr\n", 3);
}

void	ft_rrotate_2(t_stack *s1, t_stack *s2, int p)
{
	int	tmp;
	int	i;

	if (s1->n < 2 || s2->n < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	i = s1->n;
	tmp = s1->t[i - 1];
	while (--i > 0)
		s1->t[i] = s1->t[i - 1];
	s1->t[i] = tmp;
	i = s2->n;
	tmp = s2->t[i - 1];
	while (--i > 0)
		s2->t[i] = s2->t[i - 1];
	s2->t[i] = tmp;
	if (p)
		write(1, "rrr\n", 4);
}
