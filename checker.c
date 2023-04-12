/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:58:18 by obahi             #+#    #+#             */
/*   Updated: 2023/04/12 22:33:46 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (argc == 1)
		return (0);
	if (!ft_fill_stacks(argv, &a, &b) || !ft_duplicated(a))
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	line = get_next_line(0);
	while (line)
	{
		ft_execute(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (ft_sorted(a) && b.n == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a.t);
	free(b.t);
	return (0);
}
