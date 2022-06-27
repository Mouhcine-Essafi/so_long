/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 04:29:26 by messafi           #+#    #+#             */
/*   Updated: 2022/06/27 16:37:01 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*strnew(int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(*temp) * (size + 1));
	if (!temp)
		return (NULL);
	if (temp)
	{
		while (i <= size)
		{
			temp[i] = '\0';
			i++;
		}
	}
	return (temp);
}

static int	wordcount(char const *str, char c)
{
	int	i;
	int	timer;

	i = 0;
	timer = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			timer++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (timer);
}

static int	wordlen(char const *str, char c)
{
	int		i;
	int		timer2;

	i = 0;
	timer2 = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		timer2++;
		i++;
	}
	return (timer2);
}

char	**ft_split(char const *s, char c)
{
	char	**strmagic;
	int		i;
	int		i2;
	int		i3;

	if (!s)
		return (0);
	strmagic = malloc(sizeof(char *)
			* (wordcount(s, c) + 1));
	if (!strmagic)
		return (0);
	i = -1;
	i2 = 0;
	while (++i < wordcount(s, c))
	{
		i3 = 0;
		strmagic[i] = strnew(wordlen(&s[i2], c));
		while (s[i2] == c)
			i2++;
		while (s[i2] != c && s[i2])
			strmagic[i][i3++] = s[i2++];
		strmagic[i][i3] = '\0';
	}
	strmagic[i] = 0;
	return (strmagic);
}

