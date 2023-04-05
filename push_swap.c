/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:49:27 by obahi             #+#    #+#             */
/*   Updated: 2023/04/05 22:36:15 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = -1;
	a = ft_stack(argc - 1, 'a');
	b = ft_stack(argc - 1, 'b');
	while (++i < argc - 1)
	{
		a.t[i] = ft_atoi(*(argv + 1 + i));
		a.n++;
	}
	ft_print_stack(a);
	ft_print_stack(b);
	printf("##########\n");
	ft_sort_3(&a);
	ft_print_stack(a);
	return (0);
}