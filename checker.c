/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:50:25 by djoye             #+#    #+#             */
/*   Updated: 2019/11/12 19:25:32 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			equ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1 && s2 && s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

t_head		*rotate(t_head *head, char *buf)
{
	if ((equ("ss", buf) || equ("sa", buf)) && head->a && head->a->next)
			sa(head->a);
	if ((equ("ss", buf) || equ("sb", buf)) && head->b && head->b->next)
			sa(head->b);
	if (equ("pa", buf) && head->a)
		pa(head);
	if (equ("pb", buf) && head->b)
		pb(head);
	if ((equ("rr", buf) || equ("ra", buf)) && head->a && head->a->next)
		ra(head);
	if ((equ("rr", buf) || equ("rb", buf)) && head->b && head->b->next)
		rb(head);
	if ((equ("rrr", buf) || equ("rra", buf)) && head->a && head->a->next)
		rra(head);
	if ((equ("rrr", buf) || equ("rrb", buf)) && head->b && head->b->next)
		rrb(head);
	return (head);
}

int			main(int argc, char **argv)
{
	char	buf[1024];
	t_head	*head;
	int		i;
	int		len;
	char	*tmp;

	if (argc == 1)
		return (0);

	i = 0;
	head = NULL;
	head = read_nb(argc, argv);
	while((len = read(1, buf, 1024)) > 0)
	{
		tmp = buf;
		while(*buf && *buf != '\n' && i++)
			buf[i];
		tmp[i] = '\0';
		head = rotate(head, tmp);
	}
	if (if_sort(head->a, 1) == 1 && head->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	write(1, "\n", 1);
	while (head->b)
	{
		printf("%d stack_b\n", head->b->val);
		head->b = head->b->next;
	}
}
