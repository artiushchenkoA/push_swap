/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:32:24 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 16:32:24 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_grid *push_swap)
{
	if (push_swap->size_a <= 5)
	{
		tiny_sorting(push_swap);
		return ;
	}
	if (push_swap->disorder < 0.2)
		sort_simple(push_swap, push_swap->size_a);
	else
		sort_medium(push_swap);
}
