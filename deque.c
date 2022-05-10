/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:38:26 by stamim            #+#    #+#             */
/*   Updated: 2022/05/08 13:10:29 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_LLNode	*ft_dq_pop_back(t_Deque *const dq)
{
	t_LLNode	*tail;

	tail = NULL;
	if (dq != NULL)
	{
		tail = dq->tail;
		if (tail != NULL)
		{
			if (dq->head == tail)
				dq->head = NULL;
			dq->tail = tail->prev;
			if (dq->tail != NULL)
				dq->tail->next = NULL;
			if (tail != NULL)
			{
				tail->prev = NULL;
				tail->next = NULL;
			}
			if (dq->size > 0)
				--dq->size;
		}
	}
	return (tail);
}

t_LLNode	*ft_dq_pop_front(t_Deque *const dq)
{
	t_LLNode	*head;

	head = NULL;
	if (dq != NULL)
	{
		head = dq->head;
		if (head != NULL)
		{
			if (dq->tail == head)
				dq->tail = NULL;
			dq->head = head->next;
			if (dq->head != NULL)
				dq->head->prev = NULL;
			if (head != NULL)
			{
				head->prev = NULL;
				head->next = NULL;
			}
			if (dq->size > 0)
				--dq->size;
		}
	}
	return (head);
}

void	ft_dq_push_back(t_Deque *const dq, t_LLNode *const node)
{
	if (node != NULL)
	{
		node->prev = dq->tail;
		node->next = NULL;
		if (dq->head == NULL)
			dq->head = node;
		if (dq->tail != NULL)
			dq->tail->next = node;
		dq->tail = node;
		++dq->size;
	}
}

void	ft_dq_push_front(t_Deque *const dq, t_LLNode *const node)
{
	if (node != NULL)
	{
		node->next = dq->head;
		node->prev = NULL;
		if (dq->tail == NULL)
			dq->tail = node;
		if (dq->head != NULL)
			dq->head->prev = node;
		dq->head = node;
		++dq->size;
	}
}
