/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:09:55 by wmoughar          #+#    #+#             */
/*   Updated: 2023/01/29 13:09:55 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lowercase(unsigned long n, int *count)
{
	char	c;

	if (n >= 16)
	{
		ft_lowercase(n / 16, count);
		ft_lowercase(n % 16, count);
	}
	else
	{
		c = "0123456789abcdef"[n % 16];
		*count += write (1, &c, 1);
	}
}

void	ft_uppercase(unsigned long n, int *count)
{
	char	c;

	if (n >= 16)
	{
		ft_uppercase(n / 16, count);
		ft_uppercase(n % 16, count);
	}
	else
	{
		c = "0123456789ABCDEF"[n % 16];
		*count += write (1, &c, 1);
	}
}

void	ft_read_pointer(unsigned long n, int *count)
{
	char	c;

	if (n >= 16)
	{
		ft_read_pointer(n / 16, count);
		ft_read_pointer(n % 16, count);
	}
	else
	{
		c = "0123456789abcdef"[n % 16];
		*count += write (1, &c, 1);
	}
}

void	ft_pointer(unsigned long n, int *count)
{
	*count += write (1, "0x", 2);
	ft_read_pointer(n, count);
}
