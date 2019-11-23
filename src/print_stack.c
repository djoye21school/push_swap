/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:33:01 by djoye             #+#    #+#             */
/*   Updated: 2019/11/23 16:48:43 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			print_stack(int nb, t_stack *a, int width)
{
	char	arr[11];
	int		i;
	int		sgn;

	sgn = nb < 0 ? -1 : 1;
	nb = nb < 0 ? -nb : nb;
	i = width;
	arr[i] = '\0';
	if (a != NULL && nb == 0)
		arr[--i] = '0';
	while (i-- >= 0)
		if (nb && (arr[i] = nb % 10 + '0'))
			nb = nb / 10;
		else if (sgn == -1 && (sgn = 1))
			arr[i] = '-';
		else
			arr[i] = ' ';
	return (write(1, &arr, width));
}

void				print_head(t_head *head)
{
	t_stack *a;
	t_stack	*b;
	int		i;

	a = head->a;
	b = head->b;
	while (a || b)
	{
		print_stack(a ? a->val : 0, a, head->width);
		if (a)
			a = a->next;
		write(1, "|", 1);
		print_stack(b ? b->val : 0, b, head->width);
		if (b)
			b = b->next;
		write(1, "\n", 1);
	}
	i = head->width - 1;
	while (i-- > 0)
		write(1, " ", 1);
	write(1, "a|b\n", 6);
	i = head->width * 2;
	while (i-- > 0)
		write(1, "-", 1);
	write(1, "\n", 1);
}
