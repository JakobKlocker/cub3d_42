/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:54:50 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/03 14:30:43 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *input);
char	*swap_new_line(char *buffer);
char	*get_line_only(char *buffer);

//libft stuff
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

//strjoin
int		getlen(char *str);
char	*check_malloc(char const *s1, char const *s2);
char	*ft_strjoin1(char const *s1, char const *s2);

#endif