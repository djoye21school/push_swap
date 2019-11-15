/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:50:25 by djoye             #+#    #+#             */
/*   Updated: 2019/11/15 17:23:24 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			equ(char const *s1, char const *s2)
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

t_head		*rotate(t_head *head, char *buf)
{
	int		c;

	c = 0;
	if ((equ("ss", buf) || equ("sa", buf)) && head->a && head->a->next && ++c)
		sa(head->a);
	if ((equ("ss", buf) || equ("sb", buf)) && head->b && head->b->next && ++c)
		sa(head->b);
	if (equ("pa", buf) && head->b && ++c)
		pa(head);
	if (equ("pb", buf) && head->a && ++c)
		pb(head);
	if ((equ("rr", buf) || equ("ra", buf)) && head->a && head->a->next && ++c)
		ra(head);
	if ((equ("rr", buf) || equ("rb", buf)) && head->b && head->b->next && ++c)
		rb(head);
	if ((equ("rrr", buf) || equ("rra", buf)) && head->a && head->a->next && ++c)
		rra(head);
	if ((equ("rrr", buf) || equ("rrb", buf)) && head->b && head->b->next && ++c)
		rrb(head);
	return (c == 0 ? NULL : head);
}

int			main(int argc, char **argv)
{
	char	buf;
	t_head	*head;
	int		i;
	char	tmp[4];

	i = -1;
	if (argc == 1)
		return (0);
	if (!(head = read_nb(argc, argv)))
		return (write(1, "Error\n", 6) - 6);
	while (read(1, &buf, 1) && ++i >= 0)
	{
		if (buf == '\n' && (tmp[i] = '\0') >= 0)
		{
			head = rotate(head, tmp);
			i = -1;
		}
		else if (i < 4)
			tmp[i] = buf;
	}
	if (head == NULL || i > 3)
		return (write(1, "error\n", 6) - 6);
	if (if_sort(head->a, 1) == 1 && head->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
