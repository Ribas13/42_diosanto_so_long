/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:17 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/18 18:38:24 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_len(int n, int *len)
{
	int	nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		ft_string("-2147483648", len);
		return ;
	}
	if (nbr < 0)
	{
		ft_putcharacter_len('-', len);
		ft_putnbr_len(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr_len(nbr / 10, len);
		ft_putcharacter_len(nbr % 10 + '0', len);
	}
}
