/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:39:25 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 14:08:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = stack_a->capacity - 1;
	j = stack_b->capacity - 1;
	while (i >= 0 && j >= 0)
	{
		if (i > stack_a->top)
			printf("-	");
		else
			printf("%i	", stack_a->array[i]);
		if (j > stack_b->top)
			printf("-\n");
		else
			printf("%i\n", stack_b->array[j]);
		i--;
		j--;
	}
	printf("---------\n");
	printf("a	b\n");
}

void	display_instr(char **instr)
{
	int	i;

	i = 0;
	while (instr[i + 1])
	{
		printf("instr[%i] : \"%s\"\n", i, instr[i]);
		i++;
	}
}
