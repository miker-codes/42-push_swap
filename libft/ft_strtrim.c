/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:51:45 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 21:21:16 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	size_t	contador;

	contador = 0;
	while (set[contador] != '\0')
	{
		if (set[contador] == c)
			return (1);
		contador++;
	}
	return (0);
}

static char	*ft_copy_trim(const char *s, size_t start, size_t end)
{
	size_t			contador;
	char			*dest;

	contador = 0;
	if (end < start)
	{
		dest = malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(end - start + 2);
	if (dest == NULL)
		return (NULL);
	while (start <= end)
	{
		dest[contador] = s[start];
		contador++;
		start++;
	}
	dest[contador] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			start;
	size_t			end;

	start = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (start <= end && ft_is_in_set(s1[end], set))
		end--;
	return (ft_copy_trim(s1, start, end));
}
