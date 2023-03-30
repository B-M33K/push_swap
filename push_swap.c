/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:03:15 by obahi             #+#    #+#             */
/*   Updated: 2023/03/11 10:07:37 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	// t_stack	*b;
	t_stack *node;
	int		i;

	a = 0;
	// b = 0;
	if (argc > 2)
	{
		i = 1;
		while (*(argv + i))
		{
			node = ft_node(ft_atoi(*(argv + i)));
			ft_push(&a, node);
			i++;
		}
		// while (a)
		// {
		// 	node = ft_pop(&a);
		// 	while (b && b->data > node->data)
		// 		ft_push_2(&b, &a, 'a');
		// 	ft_push(&b, node);
		// }
		// while (b)
		// 	ft_push_2(&b, &a, 'a');
		i = ft_indexing(a);
		ft_putstack(a);
	}
	return (0);
}

