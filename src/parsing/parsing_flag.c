/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:08:10 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/23 17:08:10 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *str)
{
	if (str && str[0] == '-' && str[1] == '-' && str[2] != '\0')
	{
		if (!ft_isdigit(str[2]))
		{
			return (1);
		}
	}
	return (0);
}

void	indicate_flag(t_grid *push_swap, char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0)
		push_swap->mode = MODE_SIMPLE;
	else if (ft_strcmp(argv, "--medium") == 0)
		push_swap->mode = MODE_MEDIUM;
	else if (ft_strcmp(argv, "--complex") == 0)
		push_swap->mode = MODE_COMPLEX;
	else if (ft_strcmp(argv, "--bench") == 0)
		push_swap->bench_mode = 1;
	else
		push_swap->mode = MODE_ADAPTIVE;
}
