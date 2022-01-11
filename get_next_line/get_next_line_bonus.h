/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:02:59 by mandriic          #+#    #+#             */
/*   Updated: 2021/11/12 16:03:03 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define MAX_FD 254

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup_mod(char *s, int check);
int		ft_strlen(const char *s);
char	*ft_strjoin_mod(char *s1, char *s2);
int		ft_strchr_mod(const char *s, char c);
char	*ft_strjoin_mod2(char *s1, char *s2, char c);
#endif
