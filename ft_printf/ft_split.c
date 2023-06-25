/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:48:57 by wmoughar          #+#    #+#             */
/*   Updated: 2023/01/16 15:48:57 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//allocate n + 1 memory and return string
char	*ft_allocate(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!n)
		return (0);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//free allocated memory
char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

//calculate required memory by counting words
size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((!i && s[i] != c) || \
			(s[i] == c && s[i + 1] && s[i + 1] != c))
			count ++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str)
		return (0);
	while (i < ft_count(s, c) && s[j])
	{
		while (s[j] == c)
			j++;
		tmp = j;
		while (s[j] != c && s[j])
			j++;
		str[i] = ft_allocate(&s[tmp], j - tmp);
		if (!str[i++])
			return (ft_free(str));
	}
	str[i] = NULL;
	return (str);
}
