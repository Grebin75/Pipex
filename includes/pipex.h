/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:50:11 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/11/07 16:34:46 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include "includes/lists.h"

typedef struct s_prog	t_prog;
typedef struct s_cmd	t_cmd;

struct s_prog{
	int		infile;
	int		outfile;
	t_cmd	*cmd;
};

struct	s_cmd{
	char	*path;
	char	**cmd;
} ;

#endif
