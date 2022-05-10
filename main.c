/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:20:58 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 02:03:26 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline bool	integer_type(const char *const arg,
	const bool minus, bool *const list)
{
	unsigned short int	i;
	static char			max[11] = "2147483647";

	i = minus;
	while (arg[i])
	{
		if (arg[i] == ' ')
		{
			if (*list == false)
				return ((void)(*list = true), false);
			break ;
		}
		else if (!ft_isdigit(arg[i]))
			return (write(STDERR, ERR_MSG "\n", ft_strlen(ERR_MSG) + 1), false);
		else if (i - minus > 9)
			return (write(STDERR, ERR_MSG "\n", ft_strlen(ERR_MSG) + 1), false);
		else if (i - minus == 9)
		{
			max[9] = '7' + minus;
			if (ft_strcmp(arg + minus, max) > 0)
				return (write(STDERR, ERR_MSG "\n", ft_strlen(ERR_MSG) + 1), 0);
		}
		++i;
	}
	return (true);
}

static inline bool	append_card(const char *const arg, t_Deque *const a)
{
	static int	val;
	t_LLNode	*el;

	val = ft_atoi(arg);
	el = ft_lstnew(val);
	if (el != NULL)
	{
		if (ft_dq_none_of(a, val))
			ft_dq_push_back(a, el);
		else
		{
			free(el);
			write(STDERR, ERR_MSG "\n", ft_strlen(ERR_MSG) + 1);
			return (false);
		}
	}
	else
		return (false);
	return (true);
}

static bool	handle_integers_list(t_Deque *const a,
	const char *arg, bool *const sorted)
{
	static bool	list = true;

	while (*arg)
	{
		if (integer_type(arg, *arg == '-', &list))
		{
			if (!append_card(arg, a))
				return (false);
			if (a->size > 1)
				*sorted &= (a->tail->val > a->tail->prev->val);
		}
		else
			return (false);
		while (*arg && *arg != ' ')
			++arg;
		while (*arg && *arg == ' ')
			++arg;
	}
	return (true);
}

static inline bool	init(t_Deque *const a, char *args[], bool *const sorted)
{
	static bool	list = false;

	if (integer_type(*args, **args == '-', &list))
	{
		if (!append_card(*args, a))
			return (false);
		if (a->size > 1)
			*sorted &= (a->tail->val > a->tail->prev->val);
	}
	else if (!list || !handle_integers_list(a, *args, sorted))
		return (false);
	while (*++args != NULL)
	{
		if (integer_type(*args, **args == '-', &list))
		{
			if (!append_card(*args, a))
				return (false);
			if (a->size > 1)
				*sorted &= (a->tail->val > a->tail->prev->val);
		}
		else if (!list || !handle_integers_list(a, *args, sorted))
			return (false);
	}
	return (true);
}

int	main(const int ac, char *av[])
{
	bool	sorted;
	t_Deque	stacks[2];

	sorted = true;
	stacks[0] = (t_Deque){0};
	stacks[1] = (t_Deque){0};
	if (ac <= 1 || !init(&stacks[0], av + 1, &sorted))
	{
		ft_free_llnode(stacks[0].head);
		return (EXIT_FAILURE);
	}
	if (!sorted)
	{
		if ((stacks[0].size <= 5 && !sort_small_data(&stacks[0], &stacks[1]))
			|| (stacks[0].size > 5 && !sort(&stacks[0], &stacks[1])))
		{
			ft_free_llnode(stacks[0].head);
			ft_free_llnode(stacks[1].head);
			return (EXIT_FAILURE);
		}
	}
	ft_free_llnode(stacks[0].head);
	ft_free_llnode(stacks[1].head);
	return (EXIT_SUCCESS);
}
