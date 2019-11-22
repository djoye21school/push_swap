/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:50:25 by djoye             #+#    #+#             */
/*   Updated: 2019/11/22 15:29:15 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_head	*rotate(t_head *head, char *buf)
{
	int		c;

	c = 0;
	if ((equ("ss", buf) || equ("sa", buf)) && ++c && head->a && head->a->next)
		head->a = sa(head->a);
	if ((equ("ss", buf) || equ("sb", buf)) && ++c && head->b && head->b->next)
		head->b = sa(head->b);
	if (equ("pa", buf) && ++c && head->b)
		pa(head);
	if (equ("pb", buf) && ++c && head->a)
		pb(head);
	if ((equ("rr", buf) || equ("ra", buf)) && ++c && head->a && head->a->next)
		ra(head);
	if ((equ("rr", buf) || equ("rb", buf)) && ++c && head->b && head->b->next)
		rb(head);
	if ((equ("rrr", buf) || equ("rra", buf)) && ++c && head->a && head->a->next)
		rra(head);
	if ((equ("rrr", buf) || equ("rrb", buf)) && ++c && head->b && head->b->next)
		rrb(head);
	if (c == 0)
		exit(write(2, "Error\n", 6) - 6);
	return (head);
}

static t_head	*check(t_head *head)
{
	char	buf;
	int		i;
	char	tmp[4];

	i = 0;
	tmp[0] = '\0';
	while (read(0, &buf, 1) > 0)
	{
		if (i < 4)
			tmp[i] = (buf != '\n') ? buf : '\0';
		if (buf == '\n')
		{
			if ((head = rotate(head, tmp)) == NULL)
				exit(write(2, "Error\n", 6) - 6);
			i = -1;
			tmp[0] = '\0';
		}
		i++;
	}
	if (tmp[0] != '\0')
		head = rotate(head, tmp);
	if (i > 3)
		exit(write(2, "Error\n", 6) - 6);
	return (head);
}

int				main(int argc, char **argv)
{
	t_head		*head;
	int			flag;

	if (argc == 1)
		return (0);
	flag = (equ(argv[1], "-v") || equ(argv[1], "-vc") || equ(argv[1], "-cv")
	|| equ(argv[1], "-c")) ? 2 : 1;
	if (!(head = read_nb(argc, argv, flag)))
		exit(write(2, "Error\n", 6) - 6);
	if (!(head = check(head)))
		exit(write(2, "Error\n", 6) - 6);
	write(1, (if_sort(head->a, 1) && head->b == NULL) ? "OK\n" : "KO\n", 3);
	if (equ(argv[1], "-v") || equ(argv[1], "-vc") || equ(argv[1], "-cv"))
	{
		head->width = width(head);
		print_head(head);
	}
	exit(0);
}
