/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:57:06 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 16:44:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct		s_stack
{
	int				top;
	int				capacity;
	int				*array;
}					t_stack;

/* --------- COMMON FUNCTIONS ----------- */

/* STACK STRUCT FUNCTIONS */
t_stack	*create_stack(int capacity);
int		build_stack(int argc, char **argv, t_stack *stack_a);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
void	push(t_stack *stack, int item);
void	pop(t_stack *stack);

/* ARGUMENT CHECKS AND ERROR HANDLING */
void	free_strarray(char **array);
int		clean_and_quit(int type, t_stack *stack_a, t_stack *stack_b, char **instr);
int		check_arg(int argc, char **argv);
int		check_duplicate(int	*result, int size);

/* FUNCTIONS TO EXECUTE INSTRUCTIONS */
void	exec(t_stack *stack_a, t_stack *stack_b, char *instruction);
void	exec_instr(char **instr, t_stack *stack_a, t_stack *stack_b);

/* UTILITIES FUNCTIONS */
void	display_stack(t_stack *stack_a, t_stack *stack_b);
void	display_instr(char **instr);


/* --------- CHECKER FUNCTIONS ----------- */

/* FUNCTIONS TO READ INSTRUCTIONS */
char	**read_instr(void);


/* --------- PUSH_SWAP FUNCTIONS ----------- */

/* SORTING ALGORITHM FUNCTIONS */
void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size);
void	sort_stack_less_2(t_stack *stack_a, t_stack *stack_b);
void	sort_stack_less_3(t_stack *stack_a, t_stack *stack_b);
void	sort_stack_less_50(t_stack *stack_a, t_stack *stack_b);
void	sort_stack_less_200(t_stack *stack_a, t_stack *stack_b);
void	sort_stack_more_200(t_stack *stack_a, t_stack *stack_b);

/* SORTING UTILITIES FUNCTIONS */
int		is_sorted(t_stack *stack);
int		find_smallest(t_stack *stack);
int		find_largest(t_stack *stack);
int		find_pos(t_stack *stack, int value);
void	move_to_top(t_stack *stack_a, t_stack *stack_b, int value, int position);
void	move_to_top2(t_stack *stack_a, t_stack *stack_b, int value, int position);

/* UTILITIES FUNCTIONS FOR BIG STACKS */
long	find_chunksize(t_stack *stack, int num);
int		scan_top(t_stack *stack, long chunk_size, int chunk, int offset);
int		scan_bottom(t_stack *stack, long chunk_size, int chunk, int offset);
void	closest_top(t_stack *stack_a, t_stack *stack_b, int h_first, int h_last);
int		find_closest_sup(t_stack *stack, int value);
void	prep_b_stack(t_stack *stack_a, t_stack *stack_b);
void	handle_chunks(t_stack *stack_a, t_stack *stack_b, int chnum, long chsize);
void	b_to_a(t_stack *stack_a, t_stack *stack_b);

#endif
