/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:04:52 by stamim@stud       #+#    #+#             */
/*   Updated: 2022/05/10 01:49:38 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

# ifdef STDOUT_FILENO
// # define STDIN STDIN_FILENO
#  define STDOUT STDOUT_FILENO
#  define STDERR STDERR_FILENO
# else
// # define STDIN 0
#  define STDOUT 1
#  define STDERR 2
# endif

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define ERR_MSG "Error"
# define DUPS "DUPLICATES!"
# define SORTED_ALERT "INPUT IS SORTED!"

typedef struct s_LLNode
{
	struct s_LLNode	*next;
	struct s_LLNode	*prev;
	unsigned int	index;
	int				val;
}	t_LLNode;

typedef struct s_Deque
{
	t_LLNode		*head;
	t_LLNode		*tail;
	unsigned int	size;
}	t_Deque;

//
// write_functions.c
//
unsigned int	ft_strlen(const char *const s);
int				ft_puts(const char *const s);
int				ft_strcmp(const char *s1, const char *s2);

//
// helpers.c
//
bool			ft_isdigit(const char c);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);

//
// deque_methods.c
//
t_LLNode		*ft_lstnew(const int val);
bool			ft_dq_none_of(const t_Deque *const dq, const int val);
void			ft_free_llnode(t_LLNode *head);

//
// deque.c
//
t_LLNode		*ft_dq_pop_back(t_Deque *const dq);
t_LLNode		*ft_dq_pop_front(t_Deque *const dq);
void			ft_dq_push_back(t_Deque *const dq, t_LLNode *const node);
void			ft_dq_push_front(t_Deque *const dq, t_LLNode *const node);

//
// operations.c
//
bool			bind(const char *const op,
					t_Deque *const a, t_Deque *const b, const bool log);

//
// sort.c
//
bool			handle_three_numbers(t_Deque *const a);
bool			sort(t_Deque *const a, t_Deque *const b);
void			ping_pong_merge(
					t_Deque *const a, t_Deque *const b, const bool make_pivot);

//
// sort.c
//
int				middle_val(const t_Deque *a);
bool			handle_three_numbers(t_Deque *const a);
bool			sort_small_data(t_Deque *const a, t_Deque *const b);

#endif // !MAIN_H
