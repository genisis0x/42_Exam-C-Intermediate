/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 07:42:14 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/17 15:57:44 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

#define MAX(a, b) (a > b ? a : b)

int recursion(struct s_node *node, int parent_value, int depth)
{
	if(!node)
		return 0;
	else
	{
		int current = 1;
		if(node->value == parent_value + 1)
			current = depth + 1;
		return MAX(MAX(recursion(node->left, node->value, current), recursion(node->right, node->value, current)), current);
	}
}


int	longest_sequence(struct s_node *node)
{
	return recursion(node, ~0u, 0);
}

/*
#include <stdlib.h>
#include <stdio.h>
struct s_node *new(int item)
{
	struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
	node->left = NULL;
	node->right = NULL;
	node->value = item;
	return node;
}

int main (void)
{
	struct s_node *n = new(10);
	n->left = new(5);
	n->left->left = new(6);
	n->left->right = new(9);
	n->left->left->left = new(7);
	n->left->left->right = new(13);

	printf("The longest_sequence of the tree is: %d\n", longest_sequence(n));
	printf("The longest_sequence of the NULL tree is: %d\n", longest_sequence(0));
	printf("The value of ~0u >> 1 + 1 is: %d", (~0u >> 1) + 1);
	return 0;
}
*/
