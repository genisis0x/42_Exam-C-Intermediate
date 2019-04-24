/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 01:48:46 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/24 02:06:24 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *next;
};

int    is_looping(struct s_node *node)
{
	while(node)
	{
		if(node->value == -1)
			return 1;
		node->value = -1;
		node = node->next;
	}
	return 0;
}

/****************
  TEST MAIN
****************/

#include <stdlib.h>
#include <stdio.h>
struct s_node *new (int item)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->next = NULL;
	node->value = item;
	return node;
}

int main(void)
{
	struct s_node *l = new (1);
	l->next = new (2);
	l->next->next = new (3);
	l->next->next->next = new (4);
	l->next->next->next->next = l;
	printf("The value of is_looping is %d\n", is_looping(l));

	struct s_node *a = new (1);
	a->next = new (2);
	a->next->next = new (3);
	a->next->next->next = new (4);
	a->next->next->next->next = new (5);
	printf("The value of is_looping is %d\n", is_looping(a));
	return 0;
}
