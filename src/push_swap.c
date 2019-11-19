/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:41:18 by djoye             #+#    #+#             */
/*   Updated: 2019/11/19 20:17:26 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		equ(char const *s1, char const *s2)
{
	while (s1 && s2 && *s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 && s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

static t_head	*refresh(t_head *head)
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

static int		compl(t_head *head, int c)
{
	int			i;

	i = 0;
	if (head->a->val > head->a->next->val && head->b->val < head->b->next->val)
	{
		i++;
		head->a = sa(head->a);
		head->b = sa(head->b);
		c == 1 ? write(1, "\x1b[1;33mss\x1b[0m\n", 14) : write(1, "ss\n", 3);
	}
	else if (head->a->val > head->a_med && head->b->val < head->b_med && ++i)
	{
		head = rb(ra(head));
		c == 1 ? write(1, "\x1b[1;33mrr\x1b[0m\n", 14) : write(1, "rr\n", 3);
	}
	else if (head->a_last->val < head->a_med && head->b_last->val > head->b_med)
	{
		i++;
		head = rrb(rra(head));
		c == 1 ? write(1, "\x1b[1;33mrrr\x1b[0m\n", 15) : write(1, "rrr\n", 4);
	}
	return (i);
}

static int		sort_lite(t_head *head, int c)
{
	int			i;

	i = 0;
	if (head->a && head->a->next && head->a->val > head->a->next->val &&
	head->a->val != head->a_max)
	{
		i++;
		head->a = sa(head->a);
		c == 1 ? write(1, "\x1b[1;33msa\x1b[0m\n", 14) : write(1, "sa\n", 3);
	}
	else if (head->a && head->a->next && head->a->val > head->a_last->val)
	{
		i++;
		head = ra(head);
		c == 1 ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) : write(1, "ra\n", 3);
	}
	else if (head->a && head->a->next && head->a_last->val < head->a->val)
	{
		i++;
		head = rra(head);
		c == 1 ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) : write(1, "rra\n", 4);
	}
	return (i);
}

static int		sort_hard(t_head *head, int c)
{
	int			i;

	i = 0;
	/*head = */refresh(head);
	if (head->a && head->a->next && head->a->val > head->a->next->val &&
	head->a->val != head->a_max)
	{
		head->a = sa(head->a);
		c == 1 ? write(1, "\x1b[1;33msa\x1b[0m\n", 14) : write(1, "sa\n", 3);
	}
	else if (head->b && head->b->next && head->b->val < head->b->next->val &&
			head->b->val != head->b_min)
	{
		head->b = sa(head->b);
		c == 1 ? write(1, "\x1b[1;33msb\x1b[0m\n", 14) : write(1, "sb\n", 3);
	}
	else if (head->a && head->a->next && head->a->val > head->a_med) //&& head->a->val > head->a_last->val)//
	{
		head = ra(head);
		c == 1 ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) : write(1, "ra\n", 3);
	}
	else if (head->b && head->b->next && head->b->val < head->b_med) //&& head->b->val < head->b_last->val)//
	{
		head = rb(head);
		c == 1 ? write(1, "\x1b[1;33mrb\x1b[0m\n", 14) : write(1, "rb\n", 3);
	}
	else if (head->a && head->a->next && head->a_last->val < head->a_med) //&& head->a_last->val < head->a->val) // 
	{
		head = rra(head);
		c == 1 ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) : write(1, "rra\n", 4);
	}
	else if (head->b && head->b->next && head->b_last->val > head->b_med) //&& head->b_last->val > head->b->val) //
	{
		head = rrb(head);
		c == 1 ? write(1, "\x1b[1;33mrrb\x1b[0m\n", 15) : write(1, "rrb\n", 4);
	}
	return (i);
}

static t_head			*algo(t_head *head, int c)
{
	if (head->a && head->b && head->a->next && head->b->next && compl(head, c))
		return (head);
	if (head->b == NULL && sort_lite(head, c) == 1)
		return (head);
	if (sort_hard(head, c))
		return (head);
	else if (head->a && !(if_sort(head->a, 1)))
	{
		head = pb(head);
		c == 1 ? write(1, "\x1b[1;33mpb\x1b[0m\n", 14) : write(1, "pb\n", 3);
	}
	else if (head->b)
	{
		head = pa(head);
		c == 1 ? write(1, "\x1b[1;33mpa\x1b[0m\n", 14) : write(1, "pa\n", 3);
	}
	return (head);
}

int				main(int ac, char **av)
{
	t_head		*head;
	int			flag;

	flag = (equ(av[1], "-v") || equ(av[1], "-vc") || equ(av[1], "-cv")
	|| equ(av[1], "-c")) ? 2 : 1;
	if (ac == 1 || !(head = read_nb(ac, av, flag)))
		exit(write(1, "Error\n", 6) - 6);
	head->width = width(head);
	head->count = ft_count(head->a);
	head->min = ft_min(head->a);
	head->max = ft_max(head->a);
	head->med = ft_med(head->a, head->min, head->max);
	//printf("%d\n%d\n%d\n%d\n", head->count, head->min, head->max, head->med);
	if (equ(av[1], "-v") || equ(av[1], "-vc") || equ(av[1], "-cv"))
		print_head(head);
	while (if_sort(head->a, 1) == 0 || head->b != NULL)
	{
		if (equ(av[1], "-c") || equ(av[1], "-vc") || equ(av[1], "-cv"))
			head = algo(head, 1);
		else
			head = algo(head, 0);
		if (equ(av[1], "-v") || equ(av[1], "-vc") || equ(av[1], "-cv"))
			print_head(head);
	}
	exit(0);
}
