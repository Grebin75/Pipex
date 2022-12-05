/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:19:20 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/12/02 15:24:08 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list	t_list;

struct s_list
{
	char	*path;
	char	**cmd;
	t_list	*next;
};

t_list	*createnode(char **cmd);
t_list	*addtolast(t_list **list, t_list *new);
t_list	*addtostart(t_list **list, t_list *new);
void	rmlist(t_list **list);
void	rmnode(t_list **list);

t_list	*selectnode(t_list *list, int n);
int		listsize(t_list *list);
t_list	*listcall(void);
void	printlist(t_list *list);

#endif
