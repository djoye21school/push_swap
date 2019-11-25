/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:41:18 by djoye             #+#    #+#             */
/*   Updated: 2019/11/25 16:48:01 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head			*refresh(t_head *head)
{
	if (head->a)
	{
		head->a_min = ft_min(head->a);
		head->a_max = ft_max(head->a);
		head->a_med = ft_med(head->a, head->a_min, head->a_max);
	}
	if (head->b)
	{
		head->b_min = ft_min(head->b);
		head->b_max = ft_max(head->b);
		head->b_med = ft_med(head->b, head->b_min, head->b_max);
	}
	return (head);
}

int				position(t_stack *stack, int nb)
{
	t_stack		*tmp;
	int			i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->val == nb)
			break ;
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

static int		step(t_head *head)
{
	int			step_rb;
	int			step_rrb;
	int			pos_min;
	int			pos_max;

	pos_min = position(head->b, head->b_min);
	pos_max = position(head->b, head->b_max);
	step_rb = pos_min < pos_max ? pos_min : pos_max;
	step_rrb = pos_min > pos_max ? pos_min : pos_max;
	step_rrb = ft_count(head->b) - step_rrb;
	return (step_rb < step_rrb ? 1 : -1);
}

t_head			*algo(t_head *head)
{
	if (head->a && head->a->next && head->b &&
	head->b->next && step(head) == 1 && head->a->val < head->b_min)
	{
		head = rb(ra(head));
		head->c ? write(1, "\x1b[1;33mrr\x1b[0m\n", 14) : write(1, "rr\n", 3);
	}
	else if (head->a && head->a->next && head->a->val < head->b_min)
	{
		head = ra(head);
		head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) : write(1, "ra\n", 3);
	}
	else if (head->b &&
	(head->b->val == head->b_max || head->b->val == head->b_min))
	{
		head = pa(head);
		head->c ? write(1, "\x1b[1;33mpa\x1b[0m\n", 14) : write(1, "pa\n", 3);
	}
	else if (head->b && head->b->next && step(head) == 1 && (head = rb(head)))
		head->c ? write(1, "\x1b[1;33mrb\x1b[0m\n", 14) : write(1, "rb\n", 3);
	else if (head->b && head->b->next && step(head) == -1 && (head = rrb(head)))
		head->c ? write(1, "\x1b[1;33mrrb\x1b[0m\n", 15) : write(1, "rrb\n", 4);
	return (head);
}

int				main(int ac, char **av)
{
	t_head		*head;

	head = NULL;
	head = add_attribut(head, ac, av);
	while (sort_lite(head))
		if (if_sort(head->a, 1))
			break ;
	if (if_sort(head->a, 1))
		exit(0);
	head = q_sort(head);
	while (head->a && head->a->next && (head = refresh(head)) &&
	(if_sort(head->a, 1) == 0 || head->a_min < head->b_max))
	{
		if (!(head->b && head->a->next && head->b->next &&
		(head = refresh(head)) && compl(head)))
			head = sort_hard(head);
		if (head->visio)
			print_head(head);
	}
	head = bal_sort(head);
	exit(0);
}
