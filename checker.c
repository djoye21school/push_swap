/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:50:25 by djoye             #+#    #+#             */
/*   Updated: 2019/11/09 19:04:09 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head		*rotate(t_head *head, t_list *t_act)
{
	if (ft_strcmp("sa", t_act->val) && head->a && head->a->next)
		sa(head->a);
	else if (ft_strcmp("sb", t_act->val) && head->b && head->b->next)
		sa(head->b);
	else if (ft_strcmp("ss",act->val) && head->a && head->b && head->a->next &&
			head->b->next)
	{
		sa(head->a);
		sa(head->b);
	}
	else if (ft_strcmp("pa", act->val) && head->a)
		pa(head);
	else if (ft_strcmp("pb", act->val) && head->b)
		pb(head);
	else if (ft_strcmp("ra", act->val) && head->a && head->a->next)
		ra(head);
	else if (ft_strcmp("rb", act->val) && head->b && head->b->next)
		rb(head);
	else if (ft_strcmp("rr", act->val) && head->a && head->b && head->a->next &&
			head->b->next)
	{
		ra(head);
		rb(head);
	}
	else if (ft_strcmp("rra", act->val) && head->a && head->a->next)
		rra(head);
	else if (ft_strcmp("rrb", act->val) && head->b && head->b->next)
		rrb(head);
	else if (ft_strcmp("rrr", act->val) && head->a && head->b && head->a->next &&
			head->b->next)
	{
		rra(head);
		rrb(head);
	}
}


t_head		*rotate(t_head *head, t_list *t_act)
{
	if (ft_strcmp("sa", t_act->val) && head->a && head->a->next)
		sa(head->a);
	else if (ft_strcmp("sb", t_act->val) && head->b && head->b->next)
		sa(head->b);
	else if (ft_strcmp("ss",act->val) && head->a && head->b && head->a->next &&
			head->b->next)
	{
		sa(head->a);
		sa(head->b);
	}
	else if (ft_strcmp("pa", act->val) && head->a)
		pa(head);
	else if (ft_strcmp("pb", act->val) && head->b)
		pb(head);
	else if (ft_strcmp("ra", act->val) && head->a && head->a->next)
		ra(head);
	else if (ft_strcmp("rb", act->val) && head->b && head->b->next)
		rb(head);
	else if (ft_strcmp("rr", act->val) && head->a && head->b && head->a->next &&
			head->b->next)
	{
		ra(head);
		rb(head);
	}
	else if (ft_strcmp("rra", act->val) && head->a && head->a->next)
		rra(head);
	else if (ft_strcmp("rrb", act->val) && head->b && head->b->next)
		rrb(head);
	else if (ft_strcmp("rrr", act->val) && head->a && head->b && head->a->next &&
			head->b->next)
	{
		rra(head);
		rrb(head);
	}
}

int		main(int argc, char **argv)
{



	if (if_sort(head->a, 1) == 1 && head->b == NULL)
		write(1, "OK\n", 3);
	else write(1, "KO\n", 3);
	return (0);
}
