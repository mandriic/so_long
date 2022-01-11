/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:26:58 by mandriic          #+#    #+#             */
/*   Updated: 2021/11/11 14:27:03 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int *num_read, char **buf, char **out, int *fd)
{
	while (1)
	{
		*num_read = (int)read(*fd, *buf, BUFFER_SIZE);
		 if (*num_read != -1)
			buf[0][*num_read] = '\0';
		if (*num_read == 0 || *num_read == -1 || (ft_strchr_mod (*buf, '\n') > 0))
		{
			if (*num_read == 0)
				buf[0][0] = '\0';
			break ;
		}
		if (!*out && num_read != 0)
			*out = ft_strdup_mod(*buf, 0);
		else if (*out)
			*out = ft_strjoin_mod(*out, *buf);
	}
}

static void	ft_write_mem(char **memory, char **buf, int count)
{
	int	i;
	int	len;

	i = 0;
	len = (ft_strlen(*buf) - ft_strchr_mod(*buf, '\n'));
	*memory = (char *)malloc(sizeof(char) * len + 1);
	while (buf[0][count] != '\0' && i < len)
		memory[0][i++] = buf[0][count++];
	memory[0][i] = '\0';
}

static void	ft_find_n(char **out, char **memory, char **buf)
{
	int	i;

	i = -1;
	if (!*out)
	{
		*out = (char *)malloc(sizeof(char) * (ft_strchr_mod(*buf, '\n') + 1));
		while (buf[0][++i] != '\n' && buf[0][i] != '\0')
			out[0][i] = buf[0][i];
		if (buf[0][i] == '\n')
			out[0][i++] = '\n';
		out[0][i] = '\0';
	}
	else
	{
		*out = ft_strjoin_mod2(*out, *buf, '\n');
		i++;
	}
	i = ft_strchr_mod(*buf, '\n');
	if (buf[0][i] != '\0')
		ft_write_mem(memory, buf, i);
}

static int	ft_chk_memory(char **memory, char **buf, char **out)
{
	if (*memory != NULL && ft_strchr_mod(*memory, '\n') != 0)
	{
		*buf = ft_strdup_mod(*memory, 1);
		*memory = NULL;
		ft_find_n(out, memory, buf);
		free(*buf);
		return (1);
	}
	if (*memory != NULL)
	{
		*out = ft_strdup_mod(*memory, 1);
		*memory = NULL;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*buf;
	int			num_read;
	char		*out;

	out = NULL;
	buf = NULL;
	num_read = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (ft_chk_memory(&memory, &buf, &out) == 1)
		return (out);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ft_read(&num_read, &buf, &out, &fd);
	if (num_read > 0)
		ft_find_n(&out, &memory, &buf);
	if (buf)
		free(buf);
	if (!out)
		return (NULL);
	return (out);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	 char *main_char;
// 	int fd;
//     //fd = open ("fd", O_RDONLY);
// 	fd = 1000;
// 	// printf("%d, %d, %s", fd, argc, *(argv + argc - 1));
// 	main_char = get_next_line(fd);
// 	printf("<-------%s------------>", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("<-------%s------------>", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("<-------%s------------>", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("<-------%s------------>", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("-------%s------------", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("GNL-------%s------------", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("GNL-------%s------------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("GNL-------%s------------\n", main_char);
// 	free(main_char);
// }
	// main_char = get_next_line(fd);
	// printf("GNL-------%s------------\n", main_char);
	// free(main_char);
	// main_char = get_next_line(fd);
	// printf("\n\n\n\n\nGNL-------%s-----------\n", main_char);
	// free(main_char);
	// main_char = get_next_line(fd);
	// printf("GNL-------%s------------\n", main_char);
	// free(main_char);
	// main_char = get_next_line(fd);
	// printf("\n\n\n\n\nGNL-------%s-----------\n", main_char);
	// free(main_char);
	// main_char = get_next_line(fd);
	// printf("GNL-------%s------------\n", main_char);
	// free(main_char);
	// main_char = get_next_line(fd);
	// printf("\n\n\n\n\nGNL-------%s-----------\n", main_char);
	// free(main_char);



// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);

// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s------------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("GNL-------%s------------\n", main_char);
// 	free(main_char);
// 		main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s-----------\n", main_char);
// 	free(main_char);
// }

// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s------------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("GNL-------%s------------\n", main_char);
// 	free(main_char);
// 		main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s-----------\n", main_char);
// 	free(main_char);


// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s------------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s------------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s----------\n", main_char);
// 	free(main_char);
// 	main_char = get_next_line(fd);
// 	printf("\n\n\n\n\nGNL-------%s------------\n", main_char);
// 	free(main_char);
 