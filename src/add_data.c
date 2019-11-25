/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:00:06 by djoye             #+#    #+#             */
/*   Updated: 2019/11/25 13:57:09 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head		*add_attribut(t_head *head, int ac, char **av)
{
	int		flag;

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

int			width(t_head *head)
{
	int		i;
	int		nb;

	head->a_min = ft_min(head->a);
	head->a_max = ft_max(head->a);
	nb = head->a_max > -head->a_min ? head->a_max : head->a_min;
	i = nb < 0 ? 1 : 0;
	nb = nb < 0 ? -nb : nb;
	while (nb && ++i)
		nb = nb / 10;
	return (i);
}

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

t_head		*add_list(long nb, t_head *head)
{
	t_stack	*stack;
	t_stack	*last;

	if (!head && (head = (t_head*)malloc(sizeof(t_head))))
	{
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
	last = head->a;
	while (last->next)
		if (nb == last->val)
			exit(write(2, "Error\n", 6) - 6);
		else
			last = last->next;
	return (head);
}

t_head		*read_nb(int argc, char **argv, int c)
{
	long double	nb;
	int			i;
	int			sgn;
	t_head		*head;

	i = 0;
	head = NULL;
	while (c < argc && argv[c][i])
	{
		sgn = (argv[c][i] == '-' && ++i) ? -1 : 1;
		if (argv[c][i] >= '0' && argv[c][i] <= '9')
		{
			nb = 0;
			while (argv[c][i] >= '0' && argv[c][i] <= '9')
				nb = nb * 10 + argv[c][i++] - '0';
			if ((long)(nb * sgn) != (int)(nb * sgn) ||
			!(head = add_list((int)(nb * sgn), head)))
				exit(write(2, "Error\n", 6) - 6);
		}
		if (argv[c][i] != ' ' && argv[c][i] != '\0' &&
		!(argv[c][i] >= '0' && argv[c][i] <= '9'))
			exit(write(2, "Error\n", 6) - 6);
		i = (argv[c][i] == '\0' && ++c < argc) ? 0 : ++i;
	}
	return (head);
}
