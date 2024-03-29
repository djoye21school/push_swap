/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:00:06 by djoye             #+#    #+#             */
/*   Updated: 2019/11/12 14:00:58 by djoye            ###   ########.fr       */
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

t_head		*add_list(int nb, t_head *head)
{
	t_stack	*stack;
	t_stack	*last;

	if (!head)
	{
		head = (t_head*)malloc(sizeof(t_head));
		last = add_data(nb);
		head->a = last;
		head->b = NULL;
	}
	else
	{
		stack = head->a_last;
		last = add_data(nb);
		stack->next = last;
		last->prev = stack;
	}
	head->a_last = last;
	return (head);
}

t_head		*read_nb(int argc, char **argv)
{
	long	nb;
	int		c;
	int		i;
	int		sgn;
	t_head	*head;

	i = 0;
	head = NULL;
	c = 1;
	while (c < argc && argv[c][i])
	{
		if ((argv[c][i] >= '0' && argv[c][i] <= '9') || argv[c][i] == '-')
		{
			nb = 0;
			sgn = (argv[c][i] == '-' && ++i) ? -1 : 1;
			while (argv[c][i] >= '0' && argv[c][i] <= '9')
				nb = nb * 10 + argv[c][i++] - '0';
			i--;
			head = add_list((int)(nb * sgn), head);
		}
		i++;
		if (argv[c][i] == '\0' && ++c < argc)
			i = 0;
	}
	return (head);
}
