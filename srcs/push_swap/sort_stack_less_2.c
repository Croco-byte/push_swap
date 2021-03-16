/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_less_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:41:06 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 16:45:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_less_2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 1)
		return ;
	if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1])
	{
		printf("sa\n");
		exec(stack_a, stack_b, "sa");
	}
}
