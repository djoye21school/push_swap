/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:59:49 by djoye             #+#    #+#             */
/*   Updated: 2019/11/09 19:22:38 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*add_data(int nb)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->val = nb;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

int			main(int argc, char **argv)
{
	int			i;
	int			nb;
	t_stack		*stack;
	t_stack		*last;
	t_head		*head;
	int			c;

	if (argc == 1)
		return (0);
	i = 0;
	stack = NULL;
	c = 1;
	while (c < argc && argv[c][i])
	{
		if (argv[c][i] >= '0' && argv[c][i] <= '9')
		{
			nb = 0;
			while (argv[c][i] >= '0' && argv[c][i] <= '9')
				nb = nb * 10 + argv[c][i++] - '0';
			i--;
			if (!stack)
			{
				head = (t_head*)malloc(sizeof(t_head));
				stack = add_data(nb);
				head->a = stack;
				head->b = NULL;
			}
			else
			{
				last = add_data(nb);
				stack->next = last;
				last->prev = stack;
				stack = stack->next;
			}
		}
		i++;
		if (c < argc - 1 && argv[c][i] == '\0')
		{
			c++;
			i = 0;
		}
	}
	head->a_last = stack;
	while (if_sort(head->a, 1) == 0 || head->b != NULL)
		head = criteria(head);
//	print_head(head);
	return (0);
}

void		print_head(t_head *head)
{
	while (head->a)
	{
		printf("%d stack_a\n", head->a->val);
		head->a = head->a->next;
	}
	write(1, "\n", 1);
	while (head->b)
	{
		printf("%d stack_b\n", head->b->val);
		head->b = head->b->next;
	}
}

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

t_head		*criteria(t_head *head)
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
	if (head->a && head->b && head->a->next && head->b->next &&
		((head->a->val == head->a_max && head->b->val == head->b_min) ||
		(head->a->val > head->a_med && head->b->val < head->b_med)))
	{
		head = ra(head);
		head = rb(head);
		write(1, "rr\n", 3);
	}
	else if (head->a && head->b && head->a->next && head->b->next &&
			((head->a_last->val == head->a_min &&
			head->b_last->val == head->b_max) ||
			(head->a_last->val < head->a_med &&
			head->b_last->val > head->b_med)))
	{
		head = rra(head);
		head = rrb(head);
		write(1, "rrr\n", 4);
	}
	else if (head->a && head->b && head->a->next && head->b->next &&
			head->a->val > head->a->next->val && head->a->val <= head->a_med &&
			head->b->val < head->b->next->val && head->b->val >= head->b_med)
	{
		head->a = sa(head->a);
		head->b = sa(head->b);
		write(1, "ss\n", 3);
	}
	else if (head->a && head->a->next && head->a->val == head->a_max)
	{
		head = ra(head);
		write(1, "ra\n", 3);
	}
	else if (head->b && head->b->next && head->b->val == head->b_min)
	{
		head = rb(head);
		write(1, "rb\n", 3);
	}
	else if (head->a && head->a->next && head->a_last->val == head->a_min)
	{
		head = rra(head);
		write(1, "rra\n", 4);
	}
	else if (head->b && head->b->next && head->b_last->val == head->b_max)
	{
		head = rrb(head);
		write(1, "rrb\n", 4);
	}
	else if (head->a && head->a->next && head->a->val > head->a->next->val &&
			head->a_last->val > head->a->next->val &&
			head->a->val <= head->a_med)
	{
		head->a = sa(head->a);
		write(1, "sa\n", 3);
	}
	else if (head->b && head->b->next && head->b->val < head->b->next->val &&
			head->b_last->val < head->b->next->val &&
			head->b->val >= head->b_med)
	{
		head->b = sa(head->b);
		write(1, "sb\n", 3);
	}
	else if (head->a && head->a->next && head->a->val > head->a_last->val &&
			head->a->val > head->a_med)
	{
		head = ra(head);
		write(1, "ra\n", 3);
	}
	else if (head->b && head->b->next && head->b->val < head->b_last->val &&
			head->b->val < head->b_med)
	{
		head = rb(head);
		write(1, "rb\n", 3);
	}
	else if (head->a && head->a->next && head->a_last->val < head->a_med &&
			head->a_last->val < head->a->val)
	{
		head = rra(head);
		write(1, "rra\n", 4);
	}
	else if (head->b && head->b->next && head->b_last->val > head->b_med &&
			head->b_last->val > head->b->val)
	{
		head = rrb(head);
		write(1, "rrb\n", 4);
	}
	else if (head->a && head->a->next && head->a->val > head->a->next->val
				&& head->a_last->val > head->a->next->val)
	{
		head->a = sa(head->a);
		write(1, "sa\n", 3);
	}
	else if (head->b && head->b->next && head->b->val < head->b->next->val &&
			head->b_last->val < head->b->next->val)
	{
		head->b = sa(head->b);
		write(1, "sb\n", 3);
	}
	else if (head->a && !(if_sort(head->a, 1)))
	{
		head = pb(head);
		write(1, "pb\n", 3);
	}
	else if (head->b)
	{
		head = pa(head);
		write(1, "pa\n", 3);
	}
	return (head);
}
