/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:59:49 by djoye             #+#    #+#             */
/*   Updated: 2019/11/09 14:46:43 by djoye            ###   ########.fr       */
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

	if (argc == 1)
		return (0);
	i = 0;
	last = NULL;
	stack = NULL;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			nb = 0;
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
				nb = nb * 10 + argv[1][i++] - '0';
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
	}
	head->a_last = stack;
	while (if_sort(head->a, 1) == 0 || head->b != NULL)
		head = criteria(head);
	print_head(head);
	return (0);
}

void		print_head(t_head *head)
{
	while (head->a)
	{
		printf("%d stack_a\n", head->a->val);
		head->a = head->a->next;
	}
	printf("\n");
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

t_stack		*sa(t_stack *stack)
{
	int		tmp;

	tmp = stack->val;
	stack->val = stack->next->val;
	stack->next->val = tmp;
	return (stack);
}

t_head		*ra(t_head *head)
{
	t_stack	*tmp;

	tmp = head->a->next;
	head->a->next->prev = NULL;
	head->a->next = NULL;
	head->a_last->next = head->a;
	head->a->prev = head->a_last;
	head->a_last = head->a;
	head->a = tmp;
	return (head);
}

t_head		*rb(t_head *head)
{
	t_stack	*tmp;

	tmp = head->b->next;
	head->b->next->prev = NULL;
	head->b->next = NULL;
	head->b_last->next = head->b;
	head->b->prev = head->b_last;
	head->b_last = head->b;
	head->b = tmp;
	return (head);
}

t_head		*rra(t_head *head)
{
	t_stack	*tmp;

	tmp = head->a_last;
	head->a_last->prev->next = NULL;
	head->a_last = head->a_last->prev;
	head->a->prev = tmp;
	tmp->next = head->a;
	head->a = tmp;
	return (head);
}

t_head		*rrb(t_head *head)
{
	t_stack	*tmp;

	tmp = head->b_last;
	head->b_last->prev->next = NULL;
	head->b_last = head->b_last->prev;
	head->b->prev = tmp;
	tmp->next = head->b;
	head->b = tmp;
	return (head);
}

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
			head->a->val > head->a->next->val && head->a->val < head->a_med &&
			head->b->val < head->b->next->val && head->b->val > head->b_med)
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
