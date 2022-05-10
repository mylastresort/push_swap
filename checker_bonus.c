/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:27:20 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 08:21:51 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline bool	integer_type(const char *const arg,
	const bool minus, unsigned short int i, bool *const list)
{
	static char			max[11] = "2147483647";

	if (arg[0] == '\0')
		return (write(STDERR, ERR_MSG "\n", ft_strlen(ERR_MSG) + 1), false);
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

static inline bool	append_card(
	const char *const arg, t_Deque *const a)
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
		if (integer_type(arg, *arg == '-', *arg == '-', &list))
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

static inline bool	init(
	t_Deque *const a, char *args[], bool *const sorted, bool list)
{
	if (integer_type(*args, **args == '-', **args == '-', &list))
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
		if (integer_type(*args, **args == '-', **args == '-', &list))
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

bool	is_sorted(const t_LLNode *head);

bool	execute(t_Deque *const a, t_Deque *const b);

int	main(const int ac, char *av[])
{
	static bool		sorted = true;
	static t_Deque	stacks[2] = {{0}, {0}};

	if (ac <= 1 || !init(&stacks[0], av + 1, &sorted, false))
	{
		ft_free_llnode(stacks[0].head);
		return (EXIT_FAILURE);
	}
	if (!sorted)
	{
		if (!execute(&stacks[0], &stacks[1]))
		{
			(ft_free_llnode(stacks[0].head), ft_free_llnode(stacks[1].head));
			return (EXIT_FAILURE);
		}
		else if (stacks[1].head != NULL || !is_sorted(stacks[0].head))
			write(STDOUT, "KO\n", 3);
		else
			write(STDOUT, "OK\n", 3);
	}
	(ft_free_llnode(stacks[0].head), ft_free_llnode(stacks[1].head));
	return (EXIT_SUCCESS);
}
