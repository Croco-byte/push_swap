/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:26:35 by user42            #+#    #+#             */
/*   Updated: 2021/03/15 12:20:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_smallest(t_stack *stack)
{
	int	i;
	int	smallest;

	i = stack->top - 1;
	smallest = stack->array[stack->top];
	while (i >= 0)
	{
		if (stack->array[i] < smallest)
			smallest = stack->array[i];
		i--;
	}
	return (smallest);
}

int		find_largest(t_stack *stack)
{
	int	i;
	int	largest;

	i = stack->top - 1;
	largest = stack->array[stack->top];
	while (i >= 0)
	{
		if (stack->array[i] > largest)
			largest = stack->array[i];
		i--;
	}
	return (largest);
}

int		find_pos(t_stack *stack, int value)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] == value)
			return (i);
		i--;
	}
	return (-1);
}

void	move_to_top(t_stack *stack_a, t_stack *stack_b, int value, int position)
{
	while (stack_a->array[stack_a->top] != value)
	{
		if (position > stack_a->top / 2)
		{
			printf("ra\n");
			exec(stack_a, stack_b, "ra");
		}
		else if (position <= stack_a->top / 2)
		{
			printf("rra\n");
			exec(stack_a, stack_b, "rra");
		}
	}
}

void	move_to_top2(t_stack *stack_a, t_stack *stack_b, int value, int position)
{
	while (stack_b->array[stack_b->top] != value)
	{
		if (position > stack_b->top / 2)
		{
			printf("rb\n");
			exec(stack_a, stack_b, "rb");
		}
		else if (position <= stack_b->top / 2)
		{
			printf("rrb\n");
			exec(stack_a, stack_b, "rrb");
		}
	}
}

int		is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] < stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
