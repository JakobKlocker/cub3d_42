/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:43:35 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/31 11:36:33 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*check_malloc(char const *s1, char const *s2)
{
	char	*ret;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = getlen((char *)s1) + getlen((char *)s2);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (++i <= n)
	{
		*(unsigned char *)s = '\0';
		s++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > 4294967295 || size > 4294967295)
		return (0);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

int	getlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
