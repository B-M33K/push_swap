/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:17:37 by obahi             #+#    #+#             */
/*   Updated: 2023/03/11 10:05:04 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_node(int data);
int		ft_size(t_stack	*stack);
void	ft_push(t_stack **stack, t_stack *node);
t_stack	*ft_pop(t_stack **stack);
void	ft_putstack(t_stack	*stack);
void	ft_swap(t_stack **stack, char c);
void	ft_rotate(t_stack **stack, char c);
void	ft_rrotate(t_stack **stack, char c);
void	ft_push_2(t_stack **src, t_stack **dst, char c);
int		ft_indexing(t_stack *stack);

#endif