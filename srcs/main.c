/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:40 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/11/09 14:28:24 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_prog	*this(void)
{
	static t_prog	prog;

	return (&prog);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 5)
		exit (1);
	parse(env, argv);
}
