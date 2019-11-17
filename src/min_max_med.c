/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_med.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:23:15 by djoye             #+#    #+#             */
/*   Updated: 2019/11/17 18:37:34 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_min(t_stack *stack)
{
	int		min;

	min = stack->val;
	while (stack)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

int			ft_max(t_stack *stack)
{
	int		max;

	max = stack->val;
	while (stack)
	{
		if (stack->val > max)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

int			ft_med(t_stack *stack, int min, int max)
{
	int		m_min;
	int		m_max;
	int		count;
	t_stack *tmp;

	tmp = stack;
	count = 0;
	while (stack && ++count)
		stack = stack->next;
	while (count > 0 && min != max)
	{
		m_min = max;
		m_max = min;
		stack = tmp;
		while (stack)
		{
			m_max = stack->val > m_max && stack->val < max ? stack->val : m_max;
			m_min = stack->val < m_min && stack->val > min ? stack->val : m_min;
			stack = stack->next;
		}
		min = m_min;
		max = m_max;
		count -= 2;
	}
	return ((min == max) ? min : (min + max) / 2);
}

int			width(t_head *head)
{
	int		i;
	int		nb;

	head->a_min = ft_min(head->a);
	head->a_max = ft_max(head->a);
	nb = head->a_max > -head->a_min ? head->a_max : head->a_min;
	i = nb < 0 ? 1 : 0;
	nb = nb < 0 ? -nb : nb;
	while (nb && ++i)
		nb = nb / 10;
	return (i);
}
