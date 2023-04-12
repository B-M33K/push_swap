/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:40:33 by obahi             #+#    #+#             */
/*   Updated: 2023/04/12 00:25:04 by obahi            ###   ########.fr       */
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

int	ft_index(t_stack a, t_stack b, int i)
{
	int	j;

	j = -1;
	while (++j < a.n - 1)
		if (b.t[i] > a.t[j] && b.t[i] < a.t[j + 1])
			return (j + 1);
	return (0);
}

int	ft_int_capacity(char *str)
{
	size_t	nb;
	int		sign;
	int		n;

	sign = 1;
	nb = 0;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		n = (int)nb;
		if (sign * nb - sign * n != 0)
			return (0);
		str++;
	}
	return (1);
}
