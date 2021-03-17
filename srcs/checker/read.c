/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:24:19 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:43:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_instr(char **instr)
{
	if (!instr)
		return (0);
	instr[0] = 0;
	return (1);
}

static int	valid_inst(char *str)
{
	if (!str)
		return (1);
	if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb") || !ft_strcmp(str, "ss")
		|| !ft_strcmp(str, "pa") || !ft_strcmp(str, "pb")
		|| !ft_strcmp(str, "ra") || !ft_strcmp(str, "rb")
		|| !ft_strcmp(str, "rr") || !ft_strcmp(str, "rra")
		|| !ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrr"))
		return (1);
	return (0);
}

static char	**add_instr(char **instr, char *str)
{
	char	**new_instr;
	int		i;

	i = 0;
	while (instr[i])
		i++;
	new_instr = malloc(sizeof(char*) * (i + 1 + 1));
	if (!new_instr)
		return (0);
	i = 0;
	while (instr[i])
	{
		new_instr[i] = instr[i];
		i++;
	}
	free(instr);
	new_instr[i] = str;
	new_instr[i + 1] = 0;
	return (new_instr);
}

char	**read_instr(void)
{
	char	**instr;
	int		reader;
	char	*line;

	line = 0;
	instr = malloc(1 * sizeof(char *));
	if (!init_instr(instr))
		return (0);
	reader = 1;
	while (reader > 0)
	{
		reader = get_next_line(0, &line);
		instr = add_instr(instr, line);
		if (!valid_inst(line))
		{
			free_strarray(instr);
			free(line);
			return (0);
		}
	}
	return (instr);
}
