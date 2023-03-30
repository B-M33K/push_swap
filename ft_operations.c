/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:23:43 by obahi             #+#    #+#             */
/*   Updated: 2023/03/10 22:21:15 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*node1;
	t_stack *node2;

	node1 = ft_pop(stack);
	node2 = ft_pop(stack);
	ft_push(stack, node1);
	ft_push(stack, node2);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	free(node1);
	free(node2);
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = 0;
	node = ft_pop(stack);
	while (*stack)
		ft_push(&tmp, ft_pop(stack));
	ft_push(stack, node);
	while(tmp)
		ft_push(stack, ft_pop(&tmp));
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	ft_rrotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = 0;
	while((*stack)->next)
		ft_push(&tmp, ft_pop(stack));
	node = ft_pop(stack);
	while(tmp)
		ft_push(stack, ft_pop(&tmp));
	ft_push(stack, node);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);	
}

void	ft_push_2(t_stack **src, t_stack **dst, char c)
{
	ft_push(dst, ft_pop(src));
	write(1, "p", 2);
	write(1, &c, 1);
	write(1, "\n", 1);	
}