/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:13:43 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/12/05 14:30:55 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lists.h"

// Return the amount of objects.
int	listsize(t_list *list)
{
	int		i;

	i = 0;
	if (!list)
		return (i);
	while (list->next && ++i)
		list = list->next;
	return (++i);
}

// Return obj on n position, return *list if n object dont exist.
t_list	*selectnode(t_list *list, int n)
{
	t_list	*temp;

	temp = list;
	if (n < 0 && !temp)
		return (NULL);
	while (temp && n--)
		temp = temp->next;
	return (temp);
}

void	printlist(t_list *list)
{
	int	i;

	while (list)
	{
		printf("PATH: %s\n", list->path);
		i = -1;
		while (list->cmd[++i])
			printf("CMD[%i]: %s\n", i, list->cmd[i]);
		list = list->next;
	}
}

// Return list address

t_list	*listcall(void)
{
	static t_list	list;

	return (&list);
}
