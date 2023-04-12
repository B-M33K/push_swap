/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:39:27 by obahi             #+#    #+#             */
/*   Updated: 2023/04/10 23:19:28 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# define MIN(a ,b) ((a < b) ? a : b)

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

void	ft_swap(t_stack *s, int p);
void	ft_rotate(t_stack *s, int p);
void	ft_rrotate(t_stack *s, int p);
void	ft_push(t_stack *src, t_stack *dst, int p);
void	ft_swap_2(t_stack *s1, t_stack *s2, int p);
void	ft_rotate_2(t_stack *s1, t_stack *s2, int p);
void	ft_rrotate_2(t_stack *s1, t_stack *s2, int p);
int		ft_min(t_stack s);
int		ft_max(t_stack s);
int		ft_int_capacity(char *str);
int		ft_index(t_stack a, t_stack b, int i);
void	ft_sort_3(t_stack *a);
int		ft_nb_moves(t_moves m);
t_moves	ft_moves(t_stack a, t_stack b, int i);
void	ft_move_it(t_stack *a, t_stack *b, t_moves m);
t_moves	ft_best_move(t_stack a, t_stack b);
char	**ft_parse(char **argv);
int		ft_length(char	**ar);
int		ft_valid_arg(char *ar);
int		ft_sorted(t_stack s);
int		ft_fill_stacks(char	**argv, t_stack	*a, t_stack *b);
t_stack	ft_stack(int n, char c);
void	ft_move_elements_to_b(t_stack *a, t_stack *b);
void	ft_move_elements_back_to_a(t_stack *a, t_stack *b);
int		ft_duplicated(t_stack a);
void	ft_execute(t_stack *a, t_stack *b, char *line);
#endif