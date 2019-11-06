/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:59:49 by djoye             #+#    #+#             */
/*   Updated: 2019/11/06 18:51:40 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*



int			criteria(int *nbr, int *stack, int count, int count_stack)
{
	int		min;
	int		max;
	int		med;

	min = ft_min(nbr, count);
	max = ft_max(nbr, count);
	med = ft_med(nbr, count, min, max);
	if (nbr[0] == max)
		ra(nbr, count);
	else if (nbr[count - 1] == min)
		rra(nbr, count);
	else if (nbr[0] > nbr[1] && nbr[0] < med && nbr[count - 1] > nbr[1])
		sa(nbr, count);
	else if (nbr[0] > nbr[count - 1] && nbr[0] > med)
		ra(nbr, count);
	else if (nbr[count - 1] < med && nbr[count - 1] < nbr[0])
		rra(nbr, count);
	else if (if_sort(nbr, 1, count) == 0)
	{
		pb(nbr, stack, count, count_stack);
		count_stack++;
		printf("%d \ntest pb\n", stack[0]);
	}
	else if (if_sort(nbr, 1, count) == 1 && count_stack > 0 && if_sort(stack, -1, count_stack) == 1)
	{
		pa(nbr, stack, count, count_stack);
		count_stack--;
		printf("%d \ntest pa\n", stack[0]);
	}

	return (count_stack);
}
*/

t_stack		*add_list(int nb)
{
	t_stack	*stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->val = nb;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

int			main(int argc, char **argv)
{
	int			i;
	int			c;
	int			nb;
	t_stack		*stack;
	t_stack		*last;
	t_head		*head;
	int			min;
	int			max;
	int			med;

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
				stack = add_list(nb);
				head->a = stack;
				head->b = NULL;
			}
			else
			{
				last = add_list(nb);
				stack->next = last;
				last->prev = stack;
				stack = last;
			}
		}
		i++;
	}
	last = stack;
//	while (stack->prev)
//		stack = stack->prev;
	head = pb(head);

	head = pb(head);
	head = pa(head);
head = pa(head);


	stack = head->a;

	printf("%d sort\n", if_sort(stack, 0));
	min = ft_min(head->a);
	max = ft_max(head->a);
	med = ft_med(stack, min, max);
	printf("%d min %d max %d med\n", min, max, med);
//	stack = rra(head->a, last);

	stack = head->a;
	while (stack)
	{
		printf("%d stack_a\n", stack->val);
		stack = stack->next;
	}
	printf("\n");

	stack = head->b;
	while (stack)
	{
		printf("%d stack_b\n", stack->val);
		stack = stack->next;
	}
/*	}
	while (if_sort(nbr, 1, c) == 0 ||
	if_sort(stack, -1, count_stack) == 0 || count_stack != 0)
	{
	count_stack = criteria(nbr, stack, c, count_stack)
//	printf("\n%d\n", if_sort(nbr, 1, c));*/
	return (0);
}

int			if_sort(t_stack *stack, int route)
{
	while (stack->next)
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

t_stack		*sa(t_stack *stack)//верхние
{
	int		tmp;

	tmp = stack->val;
	stack->val = stack->next->val;
	stack->next->val = tmp;
	write(1, "sa\n", 3);
	return (stack);
}

t_stack		*ra(t_stack *stack, t_stack *last)// первый вниз
{
	t_stack	*tmp;

	tmp = stack->next;
	last->next = stack;
	stack->next->prev = NULL;
	stack->prev = last;
	stack->next = NULL;
	write(1, "ra\n", 3);
	return (tmp);
}

t_stack		*rra(t_stack *stack, t_stack *last)// последний вверх
{
	t_stack *tmp;

	tmp = last;
	stack->prev = last;
	last->prev->next = NULL;
	last->next = stack;
	last->prev = NULL;
	write(1, "rra\n", 4);
	return (tmp);
}


t_head		*pb(t_head *head)
{
	t_stack	*tmp;

	if (head->b == NULL)
	{
		head->b = head->a;
		head->a = head->a->next;
		head->a->prev = NULL;
		head->b->prev = NULL;
		head->b->next = NULL;
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
	write(1, "pb\n", 3);
	return (head);
}

t_head		*pa(t_head *head)
{
	t_stack	*tmp;

	tmp = head->b;
	if (head->b->next)
	{
		head->b = head->b->next;
		head->b->prev = NULL;
	}
	else
		head->b = NULL;
	tmp->next = head->a;
	head->a->prev = tmp;
	head->a = tmp;

	write(1, "pa\n", 3);
	return (head);
}
/*

int			pa(int *nbr, int *stack, int count, int count_stack)
{
	int		tmp;
	int		i;

	i = -1;
	tmp = stack[0];
	while (++i < count_stack)
		stack[i] = stack[i + 1];
	i = -1;
	if (count > 0)
		while(++i < count - count_stack)
			nbr[i + 1] = nbr[i];
	nbr[0] = tmp;
}*/
