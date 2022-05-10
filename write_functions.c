/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:33:00 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 02:03:31 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	ft_strlen(const char *const s)
{
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_puts(const char *const s)
{
	unsigned int	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		if (len > 0)
			return ((int)(write(STDOUT, s, len + 1) + write(STDOUT, "\n", 1)));
		else
			return (0);
	}
	return (-1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 != '\0' && *s1 == *s2)
		{
			s1 += 1;
			s2 += 1;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
