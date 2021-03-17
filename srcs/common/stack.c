/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:09:56 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:50:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_full(t_stack *stack)
{
	if (stack->top == stack->capacity - 1)
		return (1);
	return (0);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

void	push(t_stack *stack, int item)
{
	if (is_full(stack))
		return ;
	stack->top++;
	stack->array[stack->top] = item;
}

void	pop(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->top--;
}
