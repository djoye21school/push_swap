/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:41:18 by djoye             #+#    #+#             */
/*   Updated: 2019/11/22 12:44:07 by djoye            ###   ########.fr       */
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

static int		position(t_stack *stack, int max)
{
	t_stack		*tmp;
	int			i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->val == max)
			break ;
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

static t_head	*algo(t_head *head)
{
	head = refresh(head);
	if (head->b && if_sort(head->a, 1) && head->b->val == head->b_max)
	{
		head = pa(head);
		head->c ? write(1, "\x1b[1;33mpa\x1b[0m\n", 14) : write(1, "pa\n", 3);
	}
	else if (head->b && head->b->next && if_sort(head->a, 1) &&
	position(head->b, head->b_max) < (ft_count(head->b) / 2))
	{
		head = rb(head);
		head->c ? write(1, "\x1b[1;33mrb\x1b[0m\n", 14) : write(1, "rb\n", 3);
	}
	else if (head->b && head->b->next && if_sort(head->a, 1))
	{
		head = rrb(head);
		head->c ? write(1, "\x1b[1;33mrrb\x1b[0m\n", 15) : write(1, "rrb\n", 4);
	}
	else
		head = sort_hard(head);
	return (head);
}

static t_head	*add_attribut(t_head *head, int ac, char **av)
{
	int			flag;

	flag = (ac > 1 && (equ(av[1], "-v") || equ(av[1], "-vc")
	|| equ(av[1], "-c") || equ(av[1], "-cv"))) ? 2 : 1;
	if (ac == 1 || !(head = read_nb(ac, av, flag)))
		exit(write(1, "Error\n", 6) - 6);
	head->visio = (equ(av[1], "-v") || equ(av[1], "-vc") ||
	equ(av[1], "-cv")) ? 1 : 0;
	head->c = (equ(av[1], "-c") || equ(av[1], "-vc") ||
	equ(av[1], "-cv")) ? 1 : 0;
	head->width = width(head);
	head->count = ft_count(head->a);
	head->min = ft_min(head->a);
	head->max = ft_max(head->a);
	head->med = ft_med(head->a, head->min, head->max);
	head->a_med = ft_med(head->a, head->med, head->max);
	head->b_med = ft_med(head->a, head->min, head->med);
	if (head->visio)
		print_head(head);
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
	while (head->a && head->a->next && if_sort(head->a, 1) == 0)
	{
		if (!(head->b && head->a->next && head->b->next &&
		(head = refresh(head)) && compl(head)))
			head = sort_hard(head);
		if (head->visio)
			print_head(head);
	}
	while (if_sort(head->a, 1) == 0 || head->b)
	{
		head = algo(head);
		if (head->visio)
			print_head(head);
	}
	exit(0);
}
