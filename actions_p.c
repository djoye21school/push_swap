/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:20:21 by djoye             #+#    #+#             */
/*   Updated: 2019/11/09 15:21:14 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head		*pb(t_head *head)
{
	t_stack	*tmp;

	if (head->b == NULL)
	{
		head->a->next->prev = NULL;
		head->a->prev = NULL;
		head->b = head->a;
		head->a = head->a->next;
		head->b->prev = NULL;
		head->b->next = NULL;
		head->b_last = head->b;
	}
	else
	{
		tmp = head->a;
		head->a = head->a->next;
		head->a->prev = NULL;
		tmp->next = head->b;
		head->b->prev = tmp;
		head->b = tmp;
	}
	return (head);
}

t_head		*pa(t_head *head)
{
	t_stack	*tmp;

	tmp = head->b;
	if (head->b->next)
	{
		tmp = head->b;
		head->b = head->b->next;
		head->b->prev = NULL;
		head->a->prev = tmp;
		tmp->next = head->a;
		head->a = tmp;
	}
	else
	{
		head->b = NULL;
		tmp->next = head->a;
		head->a->prev = tmp;
		head->a = tmp;
	}
	return (head);
}
