/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:23:31 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 07:11:29 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline void	move(t_Deque *const a, t_Deque *const b,
	unsigned int pointers[2], unsigned int range)
{
	if (a->head->index >= pointers[0] && a->head->index < pointers[0] + range)
	{
		bind(PB, a, b, true);
		if (b->head->next != NULL && b->head->next->index >= pointers[0]
			&& b->head->next->index < pointers[0] + range
			&& b->head->next->val > b->head->val)
			bind(SB, a, b, true);
	}
	else if (a->head->index >= pointers[1] - range
		&& a->head->index < pointers[1])
	{
		bind(PB, a, b, true);
		if (b->head->next != NULL && b->head->next->index >= pointers[1] - range
			&& b->head->next->index < pointers[1]
			&& b->head->next->val < b->head->val)
			bind(SB, a, b, true);
	}
	else
		bind(RA, a, NULL, true);
}

static inline void	push_first_runs(
	t_Deque *const a, t_Deque *const b, unsigned int range)
{
	unsigned int		j;
	static unsigned int	i = 0;
	t_LLNode			sep;

	j = a->size;
	while (i <= j)
	{
		ft_dq_push_back(a, &sep);
		while (a->head != &sep)
			move(a, b, (unsigned int [2]){i, j}, range);
		ft_dq_pop_front(a);
		i += range;
		j -= range;
	}
}

static inline void	spin(t_Deque *const a, t_Deque *const b, int depth)
{
	if (middle_val(a) > b->head->val)
	{
		while (a->head->val < b->head->val && ++depth)
			bind(RA, a, b, true);
		while (b->head != NULL && a->tail->val < b->head->val
			&& a->head->val > b->head->val)
			bind(PA, a, b, true);
		while (depth-- > 0)
			bind(RRA, a, b, true);
	}
	else
	{
		while (a->tail->val > b->head->val && ++depth)
			bind(RRA, a, b, true);
		while (b->head != NULL && a->head->val > b->head->val
			&& a->tail->val < b->head->val && ++depth)
			bind(PA, a, b, true);
		while (depth-- > 0)
			bind(RA, a, b, true);
	}
}

void	ping_pong_merge(
	t_Deque *const a, t_Deque *const b, const bool make_pivot)
{
	if (make_pivot)
	{
		if (a->head != NULL)
			while (a->head->next != NULL)
				bind(PB, a, b, true);
		else
			bind(PA, a, b, true);
	}
	while (b->head != NULL)
	{
		if (a->head->val > b->head->val)
			bind(PA, a, b, true);
		else if (a->head->next != NULL && a->head->next->val > b->head->val)
		{
			bind(PA, a, b, true);
			bind(SA, a, b, true);
		}
		else if (a->tail->val < b->head->val)
		{
			bind(PA, a, b, true);
			bind(RA, a, b, true);
		}
		else
			spin(a, b, 0);
	}
}

bool	sort(t_Deque *const a, t_Deque *const b)
{
	t_LLNode		*i;
	t_LLNode		*j;

	i = a->head;
	while (i != NULL)
	{
		j = a->head;
		while (j != NULL)
		{
			if (i->val > j->val)
				i->index += 1;
			j = j->next;
		}
		i = i->next;
	}
	if (a->size < 10)
		push_first_runs(a, b, 1);
	else if (a->size <= 100)
		push_first_runs(a, b, 7);
	else if (a->size <= 500)
		push_first_runs(a, b, (7 * (a->size - 100) / 400) + 7);
	else
		push_first_runs(a, b, 14);
	ping_pong_merge(a, b, true);
	return (true);
}
