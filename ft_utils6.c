/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:17:03 by obahi             #+#    #+#             */
/*   Updated: 2023/04/09 12:44:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	ft_stack(int n, char c)
{
	t_stack	stack;

	stack.n = 0;
	stack.c = c;
	stack.t = malloc(n * sizeof(int));
	return (stack);
}

int	ft_fill_stacks(char	**argv, t_stack	*a, t_stack *b)
{
	char	**args;
	int		n;
	int		i;

	args = ft_parse(argv);
	n = ft_length(args);
	*a = ft_stack(n, 'a');
	*b = ft_stack(n, 'b');
	if (!a->t || !b->t)
		exit(0);
	i = -1;
	while (++i < n)
	{
		if (ft_valid_arg(*(args + i)))
		{
			a->t[i] = ft_atoi(*(args + i));
			a->n++;
		}
		else
			return (0);
	}
	ft_free2(args);
	return (1);
}

void	ft_move_elements_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	if (a->n == 2)
	{
		if (a->t[0] > a->t[1])
			return (ft_swap(a, 1));
		else
			return ;
	}
	min = a->t[ft_min(*a)];
	max = a->t[ft_max(*a)];
	while (a->n > 3)
	{
		if (a->t[0] == min || a->t[0] == max)
			ft_rotate(a, 1);
		else
			ft_push(a, b, 1);
	}
	ft_sort_3(a);
}

void	ft_move_elements_back_to_a(t_stack *a, t_stack *b)
{
	t_moves	m;
	int		i;

	while (b->n > 0)
	{
		m = ft_best_move(*a, *b);
		ft_move_it(a, b, m);
	}
	i = ft_min(*a);
	if (i <= a->n / 2)
		while (i--)
			ft_rotate(a, 1);
	else
	{
		i = a->n - i;
		while (i--)
			ft_rrotate(a, 1);
	}
}

int	ft_duplicated(t_stack a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.n - 1)
	{
		j = i + 1;
		while (j < a.n)
		{
			if (a.t[i] == a.t[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
