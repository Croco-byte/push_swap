/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:45:05 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:46:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rev(t_stack *stack)
{
	int	i;
	int	*new_array;

	if (stack->top < 1)
		return ;
	i = stack->top;
	new_array = malloc(stack->capacity * sizeof(int));
	new_array[stack->top] = stack->array[0];
	while (i > 0)
	{
		new_array[i - 1] = stack->array[i];
		i--;
	}
	free(stack->array);
	stack->array = new_array;
}

void	exec_rrr(t_stack *stack_a, t_stack *stack_b)
{
	exec_rev(stack_a);
	exec_rev(stack_b);
}

void	exec(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		exec_s(stack_a);
	if (!ft_strcmp(instruction, "sb"))
		exec_s(stack_b);
	if (!ft_strcmp(instruction, "ss"))
		exec_ss(stack_a, stack_b);
	if (!ft_strcmp(instruction, "pa"))
		exec_p(stack_a, stack_b);
	if (!ft_strcmp(instruction, "pb"))
		exec_p(stack_b, stack_a);
	if (!ft_strcmp(instruction, "ra"))
		exec_r(stack_a);
	if (!ft_strcmp(instruction, "rb"))
		exec_r(stack_b);
	if (!ft_strcmp(instruction, "rr"))
		exec_rr(stack_a, stack_b);
	if (!ft_strcmp(instruction, "rra"))
		exec_rev(stack_a);
	if (!ft_strcmp(instruction, "rrb"))
		exec_rev(stack_b);
	if (!ft_strcmp(instruction, "rrr"))
		exec_rrr(stack_a, stack_b);
}

void	exec_instr(char **instr, t_stack *stack_a, t_stack *stack_b, int debug)
{
	int	i;

	i = 0;
	while (instr[i + 1])
	{
		exec(stack_a, stack_b, instr[i]);
		if (debug)
		{
			printf("\n\n%s\n", instr[i]);
			display_stack(stack_a, stack_b);
		}
		i++;
	}
}
