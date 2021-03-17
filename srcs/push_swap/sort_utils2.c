/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:01:48 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 12:02:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top(t_stack *stack_a, t_stack *stack_b, int value, int position)
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

void	move_top2(t_stack *stack_a, t_stack *stack_b, int value, int position)
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
