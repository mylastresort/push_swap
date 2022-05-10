/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:49:06 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 04:10:01 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_strdup(const char *const s)
{
	int		l;
	char	*re;

	re = NULL;
	if (s != NULL)
	{
		l = ft_strlen(s);
		re = (char *)malloc(l + 1);
		if (re != NULL)
		{
			re[l] = '\0';
			while (l--)
				re[l] = s[l];
		}
	}
	return (re);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*re;

	re = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		re = (char *)malloc(l1 + l2 + 1);
		if (re != NULL)
		{
			re[l1 + l2] = '\0';
			i = -1;
			while (++i < l1)
				re[i] = s1[i];
			while (l2--)
				re[i + l2] = s2[l2];
			free(s1);
		}
	}
	return (re);
}

static int	ft_char_index(const char *const str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

bool	is_sorted(const t_LLNode *head)
{
	if (head != NULL)
	{
		while (head->next != NULL)
		{
			if (head->val > head->next->val)
				return (false);
			head = head->next;
		}
	}
	return (true);
}

bool	execute(t_Deque *const a, t_Deque *const b)
{
	char		*ptr;
	char		*inpt;
	static char	buf[2] = {0};
	static int	end_line = 0;

	inpt = ft_strdup("");
	while (read(STDIN_FILENO, buf, 1) > 0)
		inpt = ft_strjoin(inpt, buf);
	ptr = inpt;
	end_line = ft_char_index(inpt, '\n');
	while (end_line > 0 && (inpt[end_line] == '\0' || inpt[end_line] == '\n'))
	{
		if (inpt[end_line] == '\n')
		{
			inpt[end_line] = '\0';
			if (!bind(inpt, a, b, false))
				return ((void)free(ptr), true);
			inpt += end_line + 1;
			end_line = ft_char_index(inpt, '\n');
		}
		else if (!bind(inpt, a, b, true))
			return ((void)free(ptr), false);
	}
	return ((void)free(ptr), true);
}
