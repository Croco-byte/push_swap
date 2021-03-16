/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:56:32 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 14:42:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->top != -1)
		return (0);
	i = 0;
	while (i < stack_a->top)
	{
		if (stack_a->array[i] < stack_a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**instr;

	if (argc < 2)
		return (0);
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	instr = 0;
	if (!stack_a || !stack_b || !build_stack(argc, argv, stack_a))
		return (clean_and_quit(1, stack_a, stack_b, instr));
	instr = read_instr();
	if (!instr)
		return (clean_and_quit(1, stack_a, stack_b, instr));
	exec_instr(instr, stack_a, stack_b);
	if (!check_if_sorted(stack_a, stack_b))
		printf("KO\n");
	else
		printf("OK\n");
	clean_and_quit(0, stack_a, stack_b, instr);
	return (0);
}
