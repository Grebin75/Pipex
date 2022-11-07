/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:40 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/11/07 17:00:02 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*findpath(char *env, char *str)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (env[i] != str[i])
			break ;
		if (i == 4)
			return (env + i + 1);
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*path;

	i = -1;
	(void)argv;
	if (argc != 5)
		exit (1);
	path = NULL;
	while (!path)
		path = findpath(env[++i], "PATH=");
	i = -1;
	while (++i != 2)
	printf("%s\n", path);
}
