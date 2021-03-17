/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:27:10 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 12:00:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	helper_1(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] < stack_a->array[stack_a->top - 2]
		&& stack_a->array[stack_a->top - 1] < stack_a->array[stack_a->top - 2])
	{
		printf("sa\n");
		exec(stack_a, stack_b, "sa");
	}
	if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 2]
		&& stack_a->array[stack_a->top - 1] > stack_a->array[stack_a->top - 2])
	{
		printf("sa\n");
		exec(stack_a, stack_b, "sa");
		printf("rra\n");
		exec(stack_a, stack_b, "rra");
	}
	if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 2]
		&& stack_a->array[stack_a->top - 1] < stack_a->array[stack_a->top - 2])
	{
		printf("ra\n");
		exec(stack_a, stack_b, "ra");
	}
}

static void	helper_2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[stack_a->top] < stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] < stack_a->array[stack_a->top - 2]
		&& stack_a->array[stack_a->top - 1] > stack_a->array[stack_a->top - 2])
	{
		printf("sa\n");
		exec(stack_a, stack_b, "sa");
		printf("ra\n");
		exec(stack_a, stack_b, "ra");
	}
	if (stack_a->array[stack_a->top] < stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 2]
		&& stack_a->array[stack_a->top - 1] > stack_a->array[stack_a->top - 2])
	{
		printf("rra\n");
		exec(stack_a, stack_b, "rra");
	}
}

void	sort_stack_less_3(t_stack *stack_a, t_stack *stack_b)
{
	helper_1(stack_a, stack_b);
	helper_2(stack_a, stack_b);
}
