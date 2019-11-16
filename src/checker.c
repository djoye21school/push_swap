/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:50:25 by djoye             #+#    #+#             */
/*   Updated: 2019/11/16 16:57:44 by djoye            ###   ########.fr       */
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
	if ((equ("ss", buf) || equ("sa", buf)) && ++c && head->a && head->a->next)
		sa(head->a);
	if ((equ("ss", buf) || equ("sb", buf)) && ++c && head->b && head->b->next)
		sa(head->b);
	if (equ("pa", buf) && ++c && head->b)
		pa(head);
	if (equ("pb", buf) && ++c && head->a)
		{
			printf("%d| %s\n", c, buf);
			pb(head);
		}
	
	if ((equ("rr", buf) || equ("ra", buf)) && ++c && head->a && head->a->next )
		ra(head);
	if ((equ("rr", buf) || equ("rb", buf)) && ++c && head->b && head->b->next)
		rb(head);
	if ((equ("rrr", buf) || equ("rra", buf)) && ++c && head->a && head->a->next)
		rra(head);
	if ((equ("rrr", buf) || equ("rrb", buf)) && ++c && head->b && head->b->next)
		rrb(head);
	return (c == 0 ? NULL : head);
}

int			main(int argc, char **argv)
{
	char	buf;
	t_head	*head;
	int		i;
	char	tmp[4];

	i = 0;
	if (argc == 1)
		return (0);
	if (!(head = read_nb(argc, argv)))
		exit (write(2, "Error\n", 6) - 6);
	while (read(0, &buf, 1))
	{
		if (buf == '\n')
		 {
			 tmp[i] = '\0';
			 head = rotate(head, tmp);
//			 if (head == NULL || i > 3)
//			 	exit (write(2, "Error\n", 6) - 6);
			i = 0;
			tmp[i] = '\0';
		}
		else if (i < 4)
			tmp[i] = buf;
		i++;
	}
	if (tmp[0] != '\0')
		head = rotate(head, tmp);
	if (head == NULL || i > 3)
		exit (write(2, "Error\n", 6) - 6);
	if (if_sort(head->a, 1) == 1 && head->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
//	print_head(head);
	exit (0);
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
