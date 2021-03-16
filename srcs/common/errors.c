/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:44:41 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 14:33:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strarray(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i + 1])
			free(array[i++]);
		free(array);
	}
}

int	clean_and_quit(int type, t_stack *stack_a, t_stack *stack_b, char **instr)
{
	if (instr)
		free_strarray(instr);
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
	if (type == 1)
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}

int		check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("str[i] is %c\n", str[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_arg(int argc, char **argv)
{
	int		i;
	long	temp;

	i = 1;
	while (i < argc)
	{
		if (!check_num(argv[i]))
			return (0);
		temp = ft_atol(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int		check_duplicate(int	*result, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (result[i] == result[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
