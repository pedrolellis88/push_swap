/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:02:38 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/24 11:22:41 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	safe_free_dp(void **dp)
{
	if (dp && *dp)
	{
		free(*dp);
		*dp = NULL;
	}
}

static	char	*memorize_line(char *str, char *buff)
{
	char	*temp;

	if (!str)
	{
		str = ft_strdup(buff);
		if (!str)
		{
			free(buff);
			return (NULL);
		}
	}
	else
	{
		temp = ft_strjoin(str, buff);
		if (!temp)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		free(str);
		str = temp;
	}
	return (str);
}

static	char	*line_with_nl(char *nl, char *buff, char **strp)
{
	size_t	len;
	char	*line;
	char	*temp;

	len = (size_t)(nl - *strp) + 1;
	line = ft_substr(*strp, 0, len);
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	temp = ft_strdup(nl + 1);
	if (!temp)
	{
		free(line);
		free(buff);
		return (NULL);
	}
	free(*strp);
	*strp = temp;
	free(buff);
	return (line);
}

static	char	*make_line(ssize_t n, char **strp, char *buff)
{
	char	*nl;
	char	*line;

	if (n < 0)
	{
		safe_free_dp((void **)strp);
		free(buff);
		return (NULL);
	}
	if (!*strp)
	{
		free(buff);
		return (NULL);
	}
	nl = ft_strchr(*strp, '\n');
	if (nl)
		return (line_with_nl(nl, buff, strp));
	line = ft_strdup(*strp);
	free(*strp);
	*strp = NULL;
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	ssize_t		n;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(((unsigned int)(BUFFER_SIZE) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n = 0;
	while (str == NULL || ft_strchr(str, '\n') == NULL)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buff[n] = '\0';
		str = memorize_line(str, buff);
		if (!str)
			return (NULL);
	}
	return (make_line(n, &str, buff));
}
/*#include <stdio.h>
#include <fcntl.h>
int	main(int ac, char **av)
{
	char *str;
	if (ac != 2)
		return (1);
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
