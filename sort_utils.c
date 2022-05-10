/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:07:37 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 04:52:44 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	middle_val(const t_Deque *a)
{
	unsigned int	i;
	t_LLNode		*node;

	node = a->head;
	i = a->size / 2;
	if (i != 0)
		while (node->next != NULL && i--)
			node = node->next;
	return (node->val);
}

bool	handle_three_numbers(t_Deque *const a)
{
	if (a->head->val < a->tail->val)
	{
		if (!bind(SA, a, NULL, true))
			return (false);
		if (a->head->val > a->head->next->val)
		{
			if (!bind(RA, a, NULL, true))
				return (false);
		}
	}
	else
	{
		if (a->head->val < a->head->next->val)
			return (bind(RRA, a, NULL, true));
		else if (a->head->next->val < a->tail->val)
			return (bind(RA, a, NULL, true));
		return (bind(SA, a, NULL, true) && bind(RRA, a, NULL, true));
	}
	return (true);
}

bool	sort_small_data(t_Deque *const a, t_Deque *const b)
{
	int			size;

	if (a->size == 2)
	{
		if (!bind(SA, a, NULL, true))
			return (false);
	}
	else if (a->size == 3)
	{
		if (!handle_three_numbers(a))
			return (false);
	}
	else
	{
		size = a->size;
		while (size-- > 3)
			bind(PB, a, b, true);
		if (!(a->head->val < a->head->next->val
				&& a->head->next->val < a->tail->val))
			if (!handle_three_numbers(a))
				return (false);
		ping_pong_merge(a, b, false);
	}
	return (true);
}
