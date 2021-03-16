/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:45:02 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 16:47:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size < 3)
		sort_stack_less_2(stack_a, stack_b);
	else if (size < 50)
		sort_stack_less_50(stack_a, stack_b);
	else if (size < 200)
		sort_stack_less_200(stack_a, stack_b);
	else
		sort_stack_more_200(stack_a, stack_b);
}
