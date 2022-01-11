/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:27:42 by mandriic          #+#    #+#             */
/*   Updated: 2021/11/11 14:27:54 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup_mod(char *s, int check)
{
	char	*p;
	int		count;
	int		len;

	len = (ft_strlen(s) + 1);
	p = (char *)malloc(sizeof(char) * len);
	if (NULL == p)
		return (0);
	count = 0;
	while (s[count] != '\0' && count < len)
	{	
		p[count] = s[count];
		count++;
	}
	p[count] = '\0';
	if (check == 1)
		free(s);
	return (p);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*p;
	int		count;
	int		count2;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (NULL == p)
		return (0);
	count = 0;
	while (s1[count] != '\0')
	{
		p[count] = s1[count];
		count++;
	}
	count2 = 0;
	while (s2[count2] != '\0')
	{
		p[count] = s2[count2];
		count++;
		count2++;
	}
	p[count] = '\0';
	free(s1);
	return (p);
}

char	*ft_strjoin_mod2(char *s1, char *s2, char c)
{
	char	*p;
	int		count;
	int		count2;

	p = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strchr_mod(s2, c) + 1));
	if (NULL == p)
		return (0);
	count = 0;
	while (s1[count] != '\0')
	{
		p[count] = s1[count];
		count++;
	}
	count2 = 0;
	while (s2[count2] != '\n')
	{
		p[count] = s2[count2];
		count++;
		count2++;
	}
	p[count++] = '\n';
	p[count] = '\0';
	free(s1);
	return (p);
}

int	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_strchr_mod(const char *s, char c)
{
	int	i;

	i = 1;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	if (*s == c)
	{
		return (i);
	}
	else
		return (0);
}
