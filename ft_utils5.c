/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:47:31 by obahi             #+#    #+#             */
/*   Updated: 2023/04/10 23:17:55 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_parse(char **argv)
{
	char	*args_as_line;
	char	**args;
	char	*tmp;
	int		i;

	i = 0;
	args_as_line = ft_strdup("");
	while (*(argv + (++i)))
	{
		if (**(argv + i) == '\0' || ft_isblanc(*(argv + i)))
		{
			write(2, "ERROR\n", 6);
			free(args_as_line);
			exit(1);
		}
		tmp = args_as_line;
		args_as_line = ft_strjoin(args_as_line, *(argv + i));
		free(tmp);
		tmp = args_as_line;
		args_as_line = ft_strjoin(args_as_line, " ");
		free(tmp);
	}
	args = ft_split(args_as_line, ' ');
	free(args_as_line);
	return (args);
}

int	ft_length(char	**ar)
{
	int	i;

	i = 0;
	while (*(ar + i))
		i++;
	return (i);
}

int	ft_valid_arg(char *ar)
{
	int	i;

	i = 0;
	if (*(ar + i) == '-' || *(ar + i) == '+')
		i++;
	if (!*(ar + i))
		return (0);
	while (*(ar + i))
	{
		if (!ft_isdigit(*(ar + i)))
			return (0);
		i++;
	}
	return (ft_int_capacity(ar));
}

int	ft_sorted(t_stack s)
{
	int	i;

	i = 0;
	while (i < s.n - 1)
	{
		if (s.t[i] > s.t[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_execute(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		return (ft_swap(a, 0));
	if (!ft_strcmp(line, "sb\n"))
		return (ft_swap(b, 0));
	if (!ft_strcmp(line, "ss\n"))
		return (ft_swap_2(a, b, 0));
	if (!ft_strcmp(line, "ra\n"))
		return (ft_rotate(a, 0));
	if (!ft_strcmp(line, "rb\n"))
		return (ft_rotate(b, 0));
	if (!ft_strcmp(line, "rr\n"))
		return (ft_rotate_2(a, b, 0));
	if (!ft_strcmp(line, "rra\n"))
		return (ft_rrotate(a, 0));
	if (!ft_strcmp(line, "rrb\n"))
		return (ft_rrotate(b, 0));
	if (!ft_strcmp(line, "rrr\n"))
		return (ft_rrotate_2(a, b, 0));
	if (!ft_strcmp(line, "pa\n"))
		return (ft_push(b, a, 0));
	if (!ft_strcmp(line, "pb\n"))
		return (ft_push(a, b, 0));
	write(2, "ERROR\n", 6);
	exit(0);
}
