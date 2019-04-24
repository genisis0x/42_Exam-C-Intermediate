/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:55:22 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/23 17:56:44 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
        void *content;
        struct s_node *next;
    };

int len_list(struct s_node *list)
{
	int count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return count;
}

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	void *inter = NULL;
	int len1 = len_list(lst1);
	int len2 = len_list(lst2);

	if(len1 > len2)
	{
		int d = len1 - len2;
		int i = 0;
	   	while (i < d)
		{
			lst1 = lst1->next;
			i++;
		}
	}
	else if(len2 > len1)
	{
		int d = len2 - len1;
		int j = 0;
		while (j < d)
		{
			lst2 = lst2->next;
			j++;
		}
	}
	while (lst2 && lst1)
	{
		if(lst1 == lst2)
		{
			inter = lst1->content;
		}
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return inter;
}
