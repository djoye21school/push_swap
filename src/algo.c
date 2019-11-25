/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:57:23 by djoye             #+#    #+#             */
/*   Updated: 2019/11/25 16:49:31 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_lite(t_head *head)
{
	int		i;

	i = 0;
	if (head->a && head->a->next && head->a->val > head->a->next->val &&
	head->a->val != head->a_max)
	{
		i++;
		head->a = sa(head->a);
		head->c ? write(1, "\x1b[1;33msa\x1b[0m\n", 14) : write(1, "sa\n", 3);
	}
	else if (head->a && head->a->next && head->a->val > head->a_last->val)
	{
		i++;
		head = ra(head);
		head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) : write(1, "ra\n", 3);
	}
	else if (head->a && head->a->next && head->a_last->val < head->a->val)
	{
		i++;
		head = rra(head);
		head->c ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) : write(1, "rra\n", 4);
	}
	if (head->visio && i)
		print_head(head);
	return (i);
}

t_head		*sort_hard(t_head *head)
{
	if (head->a && head->a->next && head->a->val > head->a->next->val &&
	head->a->val != head->a_max && (head->a = sa(head->a)))
		head->c ? write(1, "\x1b[1;33msa\x1b[0m\n", 14) : write(1, "sa\n", 3);
	else if (head->b && head->b->next && head->b->val < head->b->next->val &&
			head->b->val != head->b_min && (head->b = sa(head->b)))
		head->c ? write(1, "\x1b[1;33msb\x1b[0m\n", 14) : write(1, "sb\n", 3);
	else if (head->a && head->a->next && head->a->val > head->a_med &&
	(head = ra(head)))
		head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) : write(1, "ra\n", 3);
	else if (head->b && head->b->next && head->b->val < head->b_med &&
	(head = rb(head)))
		head->c ? write(1, "\x1b[1;33mrb\x1b[0m\n", 14) : write(1, "rb\n", 3);
	else if (head->a && head->a->next && head->a_last->val < head->a_med &&
	(head = rra(head)))
		head->c ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) : write(1, "rra\n", 4);
	else if (head->b && head->b->next && head->b_last->val > head->b_med &&
	(head = rrb(head)))
		head->c ? write(1, "\x1b[1;33mrrb\x1b[0m\n", 15) : write(1, "rrb\n", 4);
	else if (if_sort(head->a, 1) && head->b && (head = pa(head)))
		head->c ? write(1, "\x1b[1;33mpa\x1b[0m\n", 14) : write(1, "pa\n", 3);
	else
		((head = pb(head)) && head->c) ? write(1, "\x1b[1;33mpb\x1b[0m\n", 14) :
		write(1, "pb\n", 3);
	return (head);
}

t_head		*q_sort(t_head *head)
{
	while (head->a && head->a->next && ft_min(head->a) < head->med)
	{
		head = refresh(head);
		if (head->a && head->b && head->a->next && head->b->next && compl(head))
			head = refresh(head);
		else if (head->a && head->a->next && head->a_last->val < head->med)
		{
			head = rra(head);
			head->c ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) :
			write(1, "rra\n", 4);
		}
		else if (head->a && head->a->val < head->med && (head = pb(head)))
			head->c ? write(1, "\x1b[1;33mpb\x1b[0m\n", 14) :
			write(1, "pb\n", 3);
		else
		{
			head = ra(head);
			head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) :
			write(1, "ra\n", 3);
		}
		if (head->visio)
			print_head(head);
	}
	return (head);
}

int			compl(t_head *head)
{
	int		i;

	i = 0;
	head = refresh(head);
	if (head->a_last->val < head->a_med && head->b_last->val > head->b_med)
	{
		i++;
		head = rrb(rra(head));
		head->c ? write(1, "\x1b[1;33mrrr\x1b[0m\n", 15) : write(1, "rrr\n", 4);
	}
	else if (head->a->val > head->a_med && head->b->val < head->b_med && ++i)
	{
		head = rb(ra(head));
		head->c ? write(1, "\x1b[1;33mrr\x1b[0m\n", 14) : write(1, "rr\n", 3);
	}
	else if (head->a->val > head->a->next->val &&
	head->b->val < head->b->next->val)
	{
		i++;
		head->a = sa(head->a);
		head->b = sa(head->b);
		head->c ? write(1, "\x1b[1;33mss\x1b[0m\n", 14) : write(1, "ss\n", 3);
	}
	return (i);
}

t_head		*bal_sort(t_head *head)
{
	while ((if_sort(head->a, 1) == 0 || head->b) && head->b)
	{
		head = algo(refresh(head));
		if (head->visio)
			print_head(head);
	}
	head = refresh(head);
	while (head->a_min != head->a->val)
	{
		if (position(head->a, head->a_min) < (ft_count(head->a) / 2))
		{
			head = ra(head);
			head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) :
			write(1, "ra\n", 3);
		}
		else
		{
			head = rra(head);
			head->c ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) :
			write(1, "rra\n", 4);
		}
		if (head->visio)
			print_head(head);
	}
	return (head);
}
