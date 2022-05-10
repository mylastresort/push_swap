/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:32:10 by stamim            #+#    #+#             */
/*   Updated: 2022/05/10 02:03:29 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		i;
	bool	sign;
	int		result;

	i = 0;
	result = 0;
	sign = (str[0] == '-' && ++i);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - 48);
		++i;
	}
	if (sign)
		return (-result);
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*m_block;
	void			*result;

	i = count * size;
	result = malloc(i);
	m_block = (unsigned char *)result;
	if (result != NULL)
	{
		while (i--)
			*m_block++ = 0;
	}
	return (result);
}
