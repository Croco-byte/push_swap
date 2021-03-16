/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:50:16 by user42            #+#    #+#             */
/*   Updated: 2021/01/08 15:21:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	k;
	char	*result;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (0);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) *sizeof(char));
	if (!result)
		return (0);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	if (c != 0)
		result[i++] = c;
	while (k < ft_strlen(s2))
	{
		result[i + k] = s2[k];
		k++;
	}
	result[i + k] = '\0';
	return (result);
}
