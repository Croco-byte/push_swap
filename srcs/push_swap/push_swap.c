/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:55:36 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 15:09:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2)
		return (0);
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	if (!stack_a || !stack_b || !build_stack(argc, argv, stack_a))
		return (clean_quit(1, stack_a, stack_b, 0));
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b, argc - 1);
	clean_quit(0, stack_a, stack_b, 0);
	return (0);
}
