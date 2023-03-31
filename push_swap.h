/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:17:37 by obahi             #+#    #+#             */
/*   Updated: 2023/03/23 10:28:40 by obahi            ###   ########.fr       */
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

t_stack	ft_stack(int n, char c);
void	ft_print_stack(t_stack s);
void	ft_swap(t_stack *s);
void	ft_swap_2(t_stack *s1, t_stack *s2);
void	ft_rotate(t_stack *s);
void	ft_rotate_2(t_stack *s1, t_stack *s2);
void	ft_rrotate(t_stack *s);
void	ft_rrotate_2(t_stack *s1, t_stack *s2);
void	ft_push(t_stack *src, t_stack *dst);

#endif