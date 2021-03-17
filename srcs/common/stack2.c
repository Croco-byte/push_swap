/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:50:19 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:50:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (0);
	result->capacity = capacity;
	result->top = -1;
	result->array = malloc(result->capacity * sizeof(int));
	if (!result->array)
		return (0);
	return (result);
}

int	build_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;

	if (!check_arg(argc, argv))
		return (0);
	i = argc;
	while (i > 0)
	{
		push(stack_a, ft_atoi(argv[i - 1]));
		i--;
	}
	if (!check_duplicate(stack_a->array, argc - 1))
		return (0);
	return (1);
}
