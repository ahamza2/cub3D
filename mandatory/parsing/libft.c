/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:06:12 by haarab            #+#    #+#             */
/*   Updated: 2024/01/24 04:07:46 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (i < n)
	{
		while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
			i++;
		return (str1[i] - str2[i]);
	}
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		x;

	i = 0;
	x = (char)c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == x)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_atoi(char *str)
{
	int		i;
	int		n;
	int		res;

	i = 0;
	n = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 15) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			n *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * n);
}

char	*ft_strdup(const char *src)
{
	char	*n;
	int		i;

	i = 0;
	n = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!n)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		n[i] = src[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}

int	ft_isdigit(int a)
{
	if ((a >= '0' && a <= '9'))
	{
		return (1);
	}
	return (0);
}
