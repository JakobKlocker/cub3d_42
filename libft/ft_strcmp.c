/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:47 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/03 14:22:48 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	compare;

	if (s1 == NULL || s2 == NULL)
		return (0);
	compare = 0;
	while ((s1[compare] == s2[compare]) && (s1[compare] != '\0'
			&& s2[compare] != '\0'))
	{
		compare++;
	}
	return (s1[compare] - s2[compare]);
}
