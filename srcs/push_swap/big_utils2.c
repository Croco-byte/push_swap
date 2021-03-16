/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:56:35 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 16:01:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_b_stack(t_stack *stack_a, t_stack *stack_b)
{
	int b_smallest;
	int	closest_sup;

	if (is_empty(stack_b) || stack_b->top < 1)
		return ;
	b_smallest = find_smallest(stack_b);
	if (stack_a->array[stack_a->top] > find_largest(stack_b)
		|| stack_a->array[stack_a->top] < b_smallest)
		move_to_top2(stack_a, stack_b, b_smallest, find_pos(stack_b, b_smallest));
	else
	{
		closest_sup = find_closest_sup(stack_b, stack_a->array[stack_a->top]);
		move_to_top2(stack_a, stack_b, closest_sup, find_pos(stack_b, closest_sup));
	}
}

void	handle_chunks(t_stack *stack_a, t_stack *stack_b, int chnum, long chsize)
{
	int	i;
	int	offset;
	int	hold_first;
	int	hold_last;

	i = 0;
	offset = find_smallest(stack_a);
	while (i < chnum)
	{
		hold_first = 0;
		hold_last = 1;
		while (hold_first != hold_last)
		{
			hold_first = scan_top(stack_a, chsize, i, offset);
			hold_last = scan_bottom(stack_a, chsize, i, offset);
			closest_top(stack_a, stack_b, hold_first, hold_last);
			prep_b_stack(stack_a, stack_b);
			printf("pb\n");
			exec(stack_a, stack_b, "pb");
		}
		i++;
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int largest;
	
	while (!is_empty(stack_b))
	{
		largest = find_largest(stack_b);
		move_to_top2(stack_a, stack_b, largest, find_pos(stack_b, largest));
		printf("pa\n");
		exec(stack_a, stack_b, "pa");
	}
}
