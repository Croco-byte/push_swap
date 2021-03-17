/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_50.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:40:33 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:37:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_less_50(t_stack *stack_a, t_stack *stack_b)
{
	int		smallest;
	int		position;

	while (stack_a->top > 2)
	{
		smallest = find_smallest(stack_a);
		position = find_pos(stack_a, smallest);
		move_top(stack_a, stack_b, smallest, position);
		printf("pb\n");
		exec(stack_a, stack_b, "pb");
	}
	sort_stack_less_3(stack_a, stack_b);
	while (!is_empty(stack_b))
	{
		printf("pa\n");
		exec(stack_a, stack_b, "pa");
	}
}
