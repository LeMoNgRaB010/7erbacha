/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmali <youmali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 15:36:28 by youmali           #+#    #+#             */
/*   Updated: 2026/11/02 13:58:39 by youmali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	nw;
	size_t	i;

	nw = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[1 + i] == c || !s[i + 1]))
			nw++;
		i++;
	}
	return (nw);
}

static void	free_all(char **tmp, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
	tmp = NULL;
}

static char	**word_alloc(char **tmp, const char *s, char c)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (*s)
	{
		if (*s != c)
			j++;
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
		{
			tmp[k] = malloc(++j);
			if (!tmp[k])
			{
				free_all(tmp, k);
				return (NULL);
			}
			tmp[k][--j] = '\0';
			j = 0;
			k++;
		}
		s++;
	}
	return (tmp);
}

static void	copy_tmp(char **tmp, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			ft_memcpy(tmp[k], s + i - j + 1, j);
			k++;
			j = 0;
		}
		i++;
	}
}

char	**ft_split(const char *s, char c)
{
	size_t	wc;
	char	**tmp;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	tmp = malloc(sizeof(char *) * (wc + 1));
	if (!tmp)
		return (NULL);
	tmp[wc] = NULL;
	if (!word_alloc(tmp, s, c))
		return (NULL);
	copy_tmp(tmp, s, c);
	return (tmp);
}
