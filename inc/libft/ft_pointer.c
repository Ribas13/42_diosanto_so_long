/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:03:35 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/18 18:36:18 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_pointer(size_t p, int *len)
{
	if (p == 0)
	{
		ft_string("(nil)", len);
		return ;
	}
	ft_string("0x", len);
	ft_hexa_len(p, len, 'x');
}
