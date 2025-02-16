/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:11:18 by ael-khat          #+#    #+#             */
/*   Updated: 2022/01/04 15:11:35 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		my_strchr(char *s, int c);
char	*my_strjoin(char *s1, char *s2);
char	*my_strdup(char *s1);
size_t	my_strlen(char *str);

#endif
