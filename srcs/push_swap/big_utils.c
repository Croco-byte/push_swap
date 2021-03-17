/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:55:52 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:55:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_chunksize(t_stack *stack, int num)
{
	long	smallest;
	long	largest;
	long	result;

	smallest = find_smallest(stack);
	largest = find_largest(stack);
	if (((largest - smallest) % num) == 0)
		result = (largest - smallest) / num;
	else
		result = ((largest - smallest) / num) + 1;
	return (result);
}

int	scan_top(t_stack *stack, long chunk_size, int chunk, int offset)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] >= offset + (chunk * chunk_size)
			&& stack->array[i] < offset + ((chunk + 1) *chunk_size))
			return (stack->array[i]);
		i--;
	}
	return (-1);
}

int	scan_bottom(t_stack *stack, long chunk_size, int chunk, int offset)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->array[i] >= offset + (chunk * chunk_size)
			&& stack->array[i] < offset + ((chunk + 1) *chunk_size))
			return (stack->array[i]);
		i++;
	}
	return (-1);
}

void	closest_top(t_stack *stack_a, t_stack *stack_b, int h_first, int h_last)
{
	int	pos_first;
	int	pos_last;

	if (h_first == -1 || h_last == -1)
		return ;
	pos_first = find_pos(stack_a, h_first);
	pos_last = find_pos(stack_a, h_last);
	if (stack_a->top - pos_first <= pos_last + 1)
		move_top(stack_a, stack_b, h_first, pos_first);
	else
		move_top(stack_a, stack_b, h_last, pos_last);
}

int	find_closest_sup(t_stack *stack, int value)
{
	int	closest;
	int	diff;
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] > value)
		{
			closest = stack->array[i];
			diff = stack->array[i] - value;
			break ;
		}
		i--;
	}
	while (i >= 0)
	{
		if (stack->array[i] > value && stack->array[i] - value < diff)
		{
			closest = stack->array[i];
			diff = stack->array[i] - value;
		}
		i--;
	}
	return (closest);
}
