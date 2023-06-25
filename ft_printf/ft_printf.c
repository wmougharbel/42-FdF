/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:47:35 by wmoughar          #+#    #+#             */
/*   Updated: 2023/01/30 09:47:35 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, const char s, int *count)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int), count);
	if (s == 's')
		ft_putstr(va_arg(args, char *), count);
	if (s == 'p')
		ft_pointer(va_arg(args, unsigned long), count);
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), count);
	if (s == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), count);
	if (s == 'x')
		ft_lowercase(va_arg(args, unsigned int), count);
	if (s == 'X')
		ft_uppercase(va_arg(args, unsigned int), count);
	if (s == '%')
		ft_percent(count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_format(args, s[i], &count);
			i++;
		}
		else
		{
			ft_putchar(s[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
