/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:50:39 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/22 18:39:00 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_dest(char **dest, int j)
{
	int	contador;

	contador = 0;
	while (contador < j)
	{
		free(dest[contador]);
		contador++;
	}
	free(dest);
}

static size_t	ft_word_len(const char *s, size_t start, char c)
{
	size_t	contador;

	contador = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		contador++;
		start++;
	}
	return (contador);
}

static int	ft_words_number(const char *s, char c)
{
	int		number_of_words;
	size_t	contador;

	number_of_words = 0;
	contador = 0;
	while (s[contador] != '\0')
	{
		if (s[contador] != c && (contador == 0 || s[contador - 1] == c))
			number_of_words++;
		contador++;
	}
	return (number_of_words);
}

static char	**ft_fill_dest(char **dest, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			dest[j] = ft_substr(s, i, ft_word_len(s, i, c));
			if (dest[j] == NULL)
			{
				ft_free_dest(dest, j);
				return (NULL);
			}
			i = i + ft_word_len(s, i, c);
			j++;
		}
		else
			i++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;

	dest = malloc((ft_words_number(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	return (ft_fill_dest(dest, s, c));
}
