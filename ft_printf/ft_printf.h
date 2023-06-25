/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:57:20 by wmoughar          #+#    #+#             */
/*   Updated: 2023/01/29 12:57:20 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_percent(int *count);
void	ft_print_unsigned(unsigned int n, int *count);
void	ft_lowercase(unsigned long n, int *count);
void	ft_uppercase(unsigned long n, int *count);
void	ft_read_pointer(unsigned long n, int *count);
void	ft_pointer(unsigned long n, int *count);
void	ft_format(va_list args, const char s, int *count);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);

#endif