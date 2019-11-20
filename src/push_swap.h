/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:10:09 by djoye             #+#    #+#             */
/*   Updated: 2019/11/20 13:05:37 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_head
{
	int				count;
	int				color;
	int				visio;
	int				min;
	int				med;
	int				max;
	struct s_stack	*a;
	struct s_stack	*a_last;
	int				a_min;
	int				a_max;
	int				a_med;
	struct s_stack	*b;
	struct s_stack	*b_last;
	int				b_min;
	int				b_max;
	int				b_med;
	int				width;
}					t_head;

typedef struct		s_act
{
	struct s_act	*next;
	int				code;
}					t_act;

t_head				*read_nb(int argc, char **argv, int c);
t_head				*add_list(long nb, t_head *head);
t_stack				*add_data(int nb);
int					width(t_head *head);
int					if_sort(t_stack *stack, int route);
int					ft_count(t_stack *stack);
int					ft_min(t_stack *stack);
int					ft_max(t_stack *stack);
int					ft_med(t_stack *stack, int min, int max);
t_stack				*sa(t_stack *stack);
t_head				*ra(t_head *head);
t_head				*rb(t_head *head);
t_head				*rra(t_head *head);
t_head				*rrb(t_head *head);
t_head				*pb(t_head *head);
t_head				*pa(t_head *head);
t_head				*criteria(t_head *head, int flag);
void				print_head(t_head *head);

#endif
