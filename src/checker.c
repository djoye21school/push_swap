/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:50:25 by djoye             #+#    #+#             */
/*   Updated: 2019/11/18 20:48:04 by djoye            ###   ########.fr       */
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

static t_head	*rotate(t_head *head, char *buf)
{
	int		c;

	c = 0;
	if ((equ("ss", buf) || equ("sa", buf)) && ++c && head->a && head->a->next)
		sa(head->a);
	if ((equ("ss", buf) || equ("sb", buf)) && ++c && head->b && head->b->next)
		sa(head->b);
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
	return (c == 0 ? NULL : head);
}

static t_head	*check(t_head *head)
{
	char	buf;
	int		i;
	char	tmp[4];

	i = 0;
	while (read(0, &buf, 1))
	{
		if (buf == '\n')
		{
			tmp[i] = '\0';
			head = rotate(head, tmp);
			if (head == NULL || i > 3)
				return (NULL);
			i = -1;
			tmp[i] = '\0';
		}
		else if (i < 4)
			tmp[i] = buf;
		i++;
	}
	if (tmp[0] != '\0')
		head = rotate(head, tmp);
	return (i > 3 ? NULL : head);
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
