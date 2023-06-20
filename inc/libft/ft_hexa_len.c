/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:23:31 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/18 18:37:45 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*void	ft_putcharacter_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}*/

void	ft_hexa_len(unsigned long int x, int *len, char x_or_x)
{
	char	str[25];
	char	*base;
	int		i;

	if (x_or_x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base[x % 16];
		x /= 16;
		i++;
	}
	while (i--)
	{
		ft_putcharacter_len(str[i], len);
	}
}
