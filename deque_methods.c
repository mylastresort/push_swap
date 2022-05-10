/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:38:26 by stamim            #+#    #+#             */
/*   Updated: 2022/04/14 14:25:41 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_LLNode	*ft_lstnew(const int val)
{
	t_LLNode	*node;

	node = (t_LLNode *)ft_calloc(1, sizeof(t_LLNode));
	if (node != NULL)
		*node = (t_LLNode){0, .val = val};
	return (node);
}

bool	ft_dq_none_of(const t_Deque *const dq, const int val)
{
	t_LLNode	*head;

	head = dq->head;
	while (head != NULL && head != dq->tail && head->val != val)
		head = head->next;
	return (head == NULL || head->val != val);
}

void	ft_free_llnode(t_LLNode *head)
{
	t_LLNode	*next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
