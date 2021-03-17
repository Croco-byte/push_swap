/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:56:32 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:42:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack *stack_a, t_stack *stack_b)
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

void	display_result(t_stack *stack_a, t_stack *stack_b)
{
	if (!check_if_sorted(stack_a, stack_b))
		printf("KO\n");
	else
		printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**instr;
	int			debug;

	debug = 0;
	if (argc < 2)
		return (0);
	if (!ft_strcmp(argv[argc - 1], "-v"))
	{
		debug++;
		argc--;
	}
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	instr = 0;
	if (!stack_a || !stack_b || !build_stack(argc, argv, stack_a))
		return (clean_quit(1, stack_a, stack_b, instr));
	instr = read_instr();
	if (!instr)
		return (clean_quit(1, stack_a, stack_b, instr));
	exec_instr(instr, stack_a, stack_b, debug);
	display_result(stack_a, stack_b);
	clean_quit(0, stack_a, stack_b, instr);
	return (0);
}
