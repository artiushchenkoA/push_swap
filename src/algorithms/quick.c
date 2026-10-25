/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:07:23 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 18:05:54 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a(t_grid *push_swap, int len, int count_rotations)
{
	(void)count_rotations;
	if (len <= 5)
	{
		tiny_sorting(push_swap);
		return ;
	}
	sort_medium(push_swap);
}
