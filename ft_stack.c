/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:09:59 by obahi             #+#    #+#             */
/*   Updated: 2023/03/11 10:06:29 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_node(int data)
{
	t_stack	*node;

	node = 0;
	node = malloc(sizeof(t_stack));
	if (node)
	{
		node->data = data;
		node->index = 0;
		node->next = 0;
	}
	return (node);
}

int	ft_indexing(t_stack *stack)
{
	int	i = 0;
	while(stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
	return i;
}

int	ft_size(t_stack	*stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack -> next;
	}
	return (size);
}

void	ft_push(t_stack **stack, t_stack *node)
{
	node -> next = *stack;
	*stack = node;
}

t_stack	*ft_pop(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	*stack = (*stack)->next;
	return (head);
}

void	ft_putstack(t_stack	*stack)
{
	ft_putendl_fd("#################", 1);
	while (stack)
	{
		ft_putnbr_fd(stack->index, 1);
		ft_putchar_fd('=',1);
		ft_putnbr_fd(stack->data, 1);
		write(1, "\n", 1);
		stack = stack->next;
	}
}
