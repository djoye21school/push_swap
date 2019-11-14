/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:31:41 by djoye             #+#    #+#             */
/*   Updated: 2019/11/12 15:32:48 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			if_sort(t_stack *stack, int route)
{
	while (stack && stack->next)
	{
		if (route == 1 ? stack->val > stack->next->val :
				stack->next->val > stack->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}
