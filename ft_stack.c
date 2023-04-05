/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:39:14 by obahi             #+#    #+#             */
/*   Updated: 2023/04/01 17:40:00 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_stack(int n, char c)
{
	t_stack	stack;

	stack.n = 0;
	stack.c = c;
	stack.t = malloc(n * sizeof(int));
	return(stack);
}
