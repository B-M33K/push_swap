/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:40:30 by obahi             #+#    #+#             */
/*   Updated: 2023/04/12 22:34:00 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	if (!ft_fill_stacks(argv, &a, &b) || !ft_duplicated(a))
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	if (ft_sorted(a))
		return (0);
	ft_move_elements_to_b(&a, &b);
	ft_move_elements_back_to_a(&a, &b);
	free(a.t);
	free(b.t);
	return (0);
}
