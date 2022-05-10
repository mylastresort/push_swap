/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:06:35 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 03:37:27 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline void	swap(const t_Deque *const dq)
{
	int	val;

	if (dq->head != NULL && dq->head != dq->tail)
	{
		val = dq->head->val;
		dq->head->val = dq->head->next->val;
		dq->head->next->val = val;
	}
}

static inline void	push(t_Deque *const src, t_Deque *const dst)
{
	ft_dq_push_front(dst, ft_dq_pop_front(src));
}

static inline void	rotate(t_Deque *const dq)
{
	ft_dq_push_back(dq, ft_dq_pop_front(dq));
}

static inline void	rrotate(t_Deque *const dq)
{
	ft_dq_push_front(dq, ft_dq_pop_back(dq));
}

bool	bind(const char *const op,
	t_Deque *const a, t_Deque *const b, const bool log)
{
	if (!ft_strcmp(op, SA))
		return (swap(a), !log || write(STDOUT, SA"\n", 3) == 3);
	else if (!ft_strcmp(op, SB))
		return (swap(b), !log || write(STDOUT, SB"\n", 3) == 3);
	else if (!ft_strcmp(op, SS))
		return (swap(a), swap(b), !log || write(STDOUT, SS"\n", 3) == 3);
	else if (!ft_strcmp(op, PA))
		return (push(b, a), !log || write(STDOUT, PA"\n", 3) == 3);
	else if (!ft_strcmp(op, PB))
		return (push(a, b), !log || write(STDOUT, PB"\n", 3) == 3);
	else if (!ft_strcmp(op, RA))
		return (rotate(a), !log || write(STDOUT, RA"\n", 3) == 3);
	else if (!ft_strcmp(op, RB))
		return (rotate(b), !log || write(STDOUT, RB"\n", 3) == 3);
	else if (!ft_strcmp(op, RR))
		return (rotate(a), rotate(b), !log || write(STDOUT, RR"\n", 3) == 3);
	else if (!ft_strcmp(op, RRA))
		return (rrotate(a), !log || write(STDOUT, RRA"\n", 4) == 4);
	else if (!ft_strcmp(op, RRB))
		return (rrotate(b), !log || write(STDOUT, RRB"\n", 4) == 4);
	else if (!ft_strcmp(op, RRR))
		return (rrotate(a),
			rrotate(b), !log || write(STDOUT, RRR"\n", 4) == 4);
	return (write(STDERR, ERR_MSG"\n", ft_strlen(ERR_MSG) + 1), false);
}
