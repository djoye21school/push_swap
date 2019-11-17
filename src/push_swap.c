/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:41:18 by djoye             #+#    #+#             */
/*   Updated: 2019/11/17 19:06:05 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_head		*head;

	if (argc == 1 || !(head = read_nb(argc, argv)))
		exit (write(1, "Error\n", 6) - 6);
	while (if_sort(head->a, 1) == 0 || head->b != NULL)
	{
		head = criteria(head);
		head->width = width(head);
		print_head(head);
	}
	exit (0);
}

void		print_stack(int nb, int width)
{
	char	arr[11];
	int		i;

	i = width;
	arr[i] = '\0';
	while(i--)
		if (nb && (arr[i] = nb % 10 + '0'))
			nb = nb / 10;
		else arr[i] = ' ';
	write (1, &arr, width);
}

void		print_head(t_head *head)
{
	t_stack *a;
	t_stack	*b;

	a = head->a;
	b = head->b;
	while (a || b)
	{
		if (a)
		{
			print_stack(head->a->val, head->width);
			a = a->next;
		}
		if (b)
		{
			print_stack(head->b->val, head->width);
			b = b->next;
		}
		printf("\n");
	}
	write(1, "_ | _\n", 6);
	write(1, "a | b\n", 6);
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
			head->a->val >= head->a_med && head->b->val <= head->b_med)
	{
		head = ra(head);
		head = rb(head);
		write(1, "rr\n", 3);
	}
	else if (head->a && head->b && head->a->next && head->b->next &&
			head->a_last->val <= head->a_med &&
			head->b_last->val >= head->b_med)
	{
		head = rra(head);
		head = rrb(head);
		write(1, "rrr\n", 4);
	}
	else if (head->a && head->b && head->a->next && head->b->next &&
			head->a->val > head->a->next->val &&
			head->b->val < head->b->next->val)
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
