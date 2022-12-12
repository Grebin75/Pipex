/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:49:55 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 17:19:06 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	wordcount(char *str)
{
	int	i;
	int	word;

	word = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 32)
		{
			word += 1;
			i++;
		}
	}
	return (word + 1);
}

int	len(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i] && (str[i] != ':' && str[i] != 32))
		;
	return (i);
}

char	*ft_getline(int count, char *s)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * (count + 1));
	if (!line)
		printerror("Malloc error", 1);
	line[count] = 0;
	i = -1;
	while (i++ < count - 1)
		line[i] = s[i];
	return (line);
}

char	**ft_split(char *s)
{
	char	**cmd;
	char	*line;
	int		count;
	int		j;

	j = -1;
	count = wordcount(s);
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
		printerror("Malloc error", 1);
	while (*s)
	{
		while (*s == 32)
			s++;
		if (!*s)
			break ;
		count = len(s);
		line = ft_getline(count, s);
		s += count;
		cmd[++j] = line;
	}
	cmd[++j] = NULL;
	return (cmd);
}

char	*strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	k = -1;
	i += len(s1) + len(s2);
	if (!s1 || !s2)
		printerror("Command not found", 1);
	s3 = malloc(sizeof(char) * (i + 2));
	if (!s3)
		printerror("Malloc error", 1);
	while (s1[++j] && j < len(s1))
		s3[++k] = s1[j];
	s3[++k] = '/';
	j = -1;
	while (s2[++j])
		s3[++k] = s2[j];
	s3[++k] = 0;
	return (s3);
}
