/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:44:02 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/12/05 14:31:07 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lists.h"

// Create a new node and return pointer to new obj.
t_list	*createnode(char **cmd)
{
	t_list	*objs;

	objs = malloc(sizeof(t_list));
	if (!objs)
		return (NULL);
	objs->path = NULL;
	objs->cmd = cmd;
	objs->next = NULL;
	return (objs);
}

// Add a node to the start and return first obj.
t_list	*addtostart(t_list **list, t_list *new)
{
	if (!new)
		return (NULL);
	if (!list)
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
	return (new);
}

// Add a node to the end and return last obj.
t_list	*addtolast(t_list **list, t_list *new)
{
	t_list	*temp;

	if (*list)
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		temp = temp->next;
	}
	else
		*list = new;
	return (new);
}

// Remove a node on a specific position.
void	rmnode(t_list **list)
{
	t_list	*temp;
	int		i;

	temp = selectnode(*list, 0);
	if (!temp)
		return ;
	(*list) = (*list)->next;
	i = -1;
	if (temp->cmd)
	{
		while (temp->cmd[++i])
			free(temp->cmd[i]);
		free(temp->cmd);
	}
	if (temp->path)
		free(temp->path);
	if (temp)
		free(temp);
}

// Remove list.
void	rmlist(t_list **list)
{
	while (*list)
		rmnode(list);
}
