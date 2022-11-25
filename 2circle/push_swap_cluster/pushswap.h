/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:24:45 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/16 17:24:56 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./lib/include/ft_printf.h"
# include "./lib/include/get_next_line.h"
# include "./lib/include/libft.h"
# include "./linkedlist/linkedlist.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	long long		*array;
	t_LinkedList	*A;
	t_LinkedList	*B;
	t_LinkedList	*command;
	t_ListNode		element;
	int				p_first;
	int				p_second;
}					t_struct;

int			pa(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C);
int			pb(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C);
int			sa(t_LinkedList *A, t_LinkedList *C);
int			sb(t_LinkedList *B, t_LinkedList *C);
int			ss(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C);
int			ra(t_LinkedList *A, t_LinkedList *C);
int			rra(t_LinkedList *A, t_LinkedList *C);
int			rr(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C);
int			rb(t_LinkedList *B, t_LinkedList *C);
int			rrb(t_LinkedList *B, t_LinkedList *C);
int			rrr(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C);

int			c_pa(t_LinkedList *A, t_LinkedList *B);
int			c_pb(t_LinkedList *A, t_LinkedList *B);
int			c_sa(t_LinkedList *A);
int			c_sb(t_LinkedList *B);
int			c_ss(t_LinkedList *A, t_LinkedList *B);
int			c_ra(t_LinkedList *A);
int			c_rra(t_LinkedList *A);
int			c_rr(t_LinkedList *A, t_LinkedList *B);
int			c_rb(t_LinkedList *B);
int			c_rrb(t_LinkedList *B);
int			c_rrr(t_LinkedList *A, t_LinkedList *B);

void		ft_error(void);
void		initialization(t_struct *test);
void		all_free(t_struct **test);

int			argv_check(char *argv[], t_struct *test);
int			ft_atoi_revised(const char *str, t_struct *test);
void		array_sort_and_overlap_check(t_struct *test);

void		Ta_to_b(t_struct *test, int start, int end);
void		Tb_to_a(t_struct *test, int start, int end);
void		Ba_to_b(t_struct *test, int start, int end);
void		Bb_to_a(t_struct *test, int start, int end);

void		find_pivot(t_struct *test, int start, int end);
void		sort_exception_handling(t_struct *test, int start, int end, int i);
void		sort_element_three(t_struct *test, int start, int flag);
void		sort_element_two(t_struct *test, int start, int flag);
void		sort_element_one(t_struct *test, int flag);

void		sort_Ta_three(t_struct *test, int start);
void		sort_Ba_three(t_struct *test, int start);
void		sort_Tb_three(t_struct *test, int start);
void		sort_Bb_three(t_struct *test, int start);

void		sort_Ta_two(t_struct *test, int start);
void		sort_Ba_two(t_struct *test, int start);
void		sort_Tb_two(t_struct *test, int start);
void		sort_Bb_two(t_struct *test, int start);

int			Ta_order_check(t_struct *test, int start, int position);

void		short_element_handler(t_struct *test, int start, int end);

void		dispay_command(t_struct *test);

# define TA		1
# define BA		2
# define TB		3
# define BB		4

# define PA		10
# define PB		11
# define SA		12
# define SB		13
# define SS		14
# define RA		15
# define RB		16
# define RR		17
# define RRA	18
# define RRB	19
# define RRR	20

#endif