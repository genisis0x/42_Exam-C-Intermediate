/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:51:53 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/15 19:02:14 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
    int value;
    struct s_node *next;
};

int is_looping(struct s_node *node)
{
	struct s_node *f1 = node;
	struct s_node *f2 = node;

	while (f1 && f2)
	{
		f1 = f1->next;
		f2 = f2->next;
		if (f2)
			f2 = f2->next;
		if (f1 && f2 && f1 == f2)
			return 1;
	}
	return 0;
}

/****************
  TEST MAIN
****************/

#include <stdlib.h>
#include <stdio.h>
struct s_node *new(int item)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->next = NULL;
	node->value = item;
	return node;
}

int main (void)
{
	struct s_node *l = new(1);
	l->next = new(2);
	l->next->next = new(3);
	l->next->next->next = new(4);
	l->next->next->next->next = l;
	printf("The value of is_looping is %d\n", is_looping(l));
	l->next->next->next->next = new(5);
	printf("The value of is_looping is %d\n", is_looping(l));
	return 0;
}
