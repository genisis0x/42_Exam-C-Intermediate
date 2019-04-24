/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:30:26 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/14 15:16:50 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	static int height = 0;
	static int i = 0;
	if (!root)
		return -1;
	else
	{
		while (root->nodes[i])
		{
			int res = 1 + height_tree(root->nodes[i++]);
			height = (res > height) ? res : height;
		}
	}
	return(height);
}

/*************
   TEST MAIN
*************/

#include "stdio.h"
#include "stdlib.h"

struct s_node *new_node(int item)
{
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = item;
	new->nodes = malloc(1000);
	return (new);
}

int main (void)
{
	struct s_node *t = new_node(94);
	t->nodes[0] = new_node(34);
	t->nodes[1] = new_node(52);
	
	t->nodes[0]->nodes[0] = new_node(1);
	t->nodes[0]->nodes[1] = new_node(99);
	t->nodes[0]->nodes[2] = new_node(11);
	
	t->nodes[0]->nodes[1]->nodes[0] = new_node(13);
	
	
	printf("%d", height_tree(t));
	return (0);
}

