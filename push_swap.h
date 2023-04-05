/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:17:37 by obahi             #+#    #+#             */
/*   Updated: 2023/04/05 22:34:44 by obahi            ###   ########.fr       */
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
	int		*t;
	int		n;
	char	c;
}	t_stack;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_moves;

t_stack	ft_stack(int n, char c);
void	ft_print_stack(t_stack s);
void	ft_swap(t_stack *s);
void	ft_swap_2(t_stack *s1, t_stack *s2);
void	ft_rotate(t_stack *s);
void	ft_rotate_2(t_stack *s1, t_stack *s2);
void	ft_rrotate(t_stack *s);
void	ft_rrotate_2(t_stack *s1, t_stack *s2);
void	ft_push(t_stack *src, t_stack *dst);
int		ft_min(t_stack s);
int		ft_max(t_stack s);
int		min(int a, int b);
int		max(int a, int b);
int		ft_index(t_stack a, t_stack b, int i);
int		ft_nb_moves(t_moves m);
t_moves	ft_moves(t_stack a, t_stack b, int i);
void	ft_move_it(t_stack *a, t_stack *b, t_moves m);
void	ft_sort_3(t_stack *a);

#endif