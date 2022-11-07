/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:44:02 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/11/07 17:19:34 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lists.h"

// Create a new node and return pointer to new obj.
t_list	*createnode(int data, char *path, char **cmd)
{
	t_list	*objs;

	objs = malloc(sizeof(t_list));
	if (!objs)
		return (NULL);
	objs->path = path;
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
	return (temp);
}

// Remove a node on a specific position.
void	rmnode(t_list **list, int n)
{
	t_list	*temp;
	int		i;

	i = -1;
	temp = selectnode(*list, n);
	if (!temp)
		return ;
	if (n > 0)
		(selectnode(*list, n - 1))->next = selectnode(*list, n + 1);
	if (n == 0)
		(*list) = (*list)->next;
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
	while (list)
		rmnode(list, 0);
}
