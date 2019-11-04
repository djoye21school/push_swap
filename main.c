/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:59:49 by djoye             #+#    #+#             */
/*   Updated: 2019/11/04 17:44:20 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			if_sort(int *nbr, int route, int count)
{
	int		i;

	i = 0;
	while (++i < count)
		if (((route == 1) ? (nbr[i - 1] > nbr[i]) : (nbr[i - 1] < nbr[i])))
			return (0);
	return (1);
}

int			sa(int *nbr, int count)//верхние
{
	int		tmp;

	tmp = nbr[0];
	nbr[0] = nbr[1];
	nbr[1] = tmp;
	return (write(1, "sa\n", 3));
}

int			pa(int *nbr, int *stack, int count, int count_stack)
{
	int		tmp;
	int		i;

	i = -1;
	tmp = nbr[0];
	while (++i < count - count_stack - 1)
		nbr[i] = nbr[i + 1];
	i = -1;
	if (count_stack > 0)
		while(++i < count_stack)
			stack[i + 1] = stack[i]; 
	stack[0] = tmp;
	return (write(1, "pa\n", 3));
}

int			ra(int *nbr, int count)// первый вниз
{
	int		tmp;
	int		i;

	i = -1;
	tmp = nbr[0];
	while (++i < count - 1)
		nbr[i] = nbr[i + 1];
	nbr[i] = tmp;
	return (write(1, "ra\n", 3));
}

int			rra(int *nbr, int count)// последний вверх
{
	int		tmp;

	tmp = nbr[count - 1];
	while (--count > 0)
		nbr[count] = nbr[count - 1];
	nbr[count] = tmp;
	return (write(1, "rra\n", 4));
}

int			ft_med(int *nbr, int count, int min, int max)
{
	int		m_min;
	int		m_max;
	int		i;
	int		c;

	c = count;
	while (count > 0)
	{
		m_min = max;
		m_max = min;
		i = 0;
		while (i++ < c)
		{
			if (nbr[i] > m_max && nbr[i] < max)
				m_max = nbr[i];
			if (nbr[i] < m_min && nbr[i] > min)
				m_min = nbr[i];
		}
		min = m_min;
		max = m_max;
		count -= 2;
	}
	return ((min == max) ? min : (min + max) / 2);
}

int			ft_min(int *nbr, int count)
{
	int		min;
	int		i;

	i = -1;
	min = nbr[0];
	while (++i < count)
		if (nbr[i] < min)
			min = nbr[i];
	return (min);
}

int			ft_max(int *nbr, int count)
{
	int		max;
	int		i;

	i = -1;
	max = nbr[0];
	while (++i < count)
		if (nbr[i] > max)
			max = nbr[i];
	return (max);
}

int			criteria(int *nbr, int *stack, int count, int count_stack)
{
	int		min;
	int		max;
	int		med;
//	int		count_stack;

//	count_stack = 0;
	min = ft_min(nbr, count);
	max = ft_max(nbr, count);
	med = ft_med(nbr, count, min, max);
	if (nbr[0] == max)
		ra(nbr, count);
	else if (nbr[count - 1] == min)
		rra(nbr, count);
	else if (nbr[0] > nbr[1] && nbr[0] <= med && nbr[count - 1] > nbr[1])
		sa(nbr, count);
	else if (nbr[0] > nbr[count - 1] && nbr[0] >= med)
		ra(nbr, count);
	else if (nbr[count - 1] <= med && nbr[count - 1] < nbr[0])
		rra(nbr, count);
	else if (if_sort(nbr, 1, count) == 0)
	{
		pa(nbr, stack, count, count_stack);
		count_stack++;
		printf("%d\n", stack[0]);
	}
	return (count_stack);
}

int			main(int argc, char **argv)
{
	int		i;
	int		c;
	int		nb;
	int		*nbr;
	int		*stack;
	int		count_stack;

	if (argc == 1)
		return (0);
	i = 0;
	c = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			while (argv[1][i] >= '0' && argv[1][i] <= '9' && argv[1][i])
				i++;
			i--;
			c++;
		}
		i++;
	}
	nbr = (int *)malloc(sizeof(int) * (c + 1));
	stack = (int *)malloc(sizeof(int) * (c + 1));
	i = 0;
	c = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			nb = 0;
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				nb = nb * 10 + argv[1][i] - '0';
				i++;
			}
			i--;
			nbr[c] = nb;
			c++;
		}
		i++;
	}
	count_stack = 0;
	while ((count_stack = criteria(nbr, stack, c, count_stack) >= 0) && (i = -1) && printf("-\n"))
		while (++i < c)
			printf("%d\n", nbr[i]);
	printf("\n%d\n", if_sort(nbr, 1, c));
	return (0);
}
