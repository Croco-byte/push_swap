/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_200.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:54:27 by user42            #+#    #+#             */
/*   Updated: 2021/03/15 15:55:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_more_200(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_number;
	int	chunk_size;

	chunk_number = 12;
	chunk_size = find_chunksize(stack_a, chunk_number);
	handle_chunks(stack_a, stack_b, chunk_number, chunk_size);
	b_to_a(stack_a, stack_b);
}
