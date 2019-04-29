/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 00:53:07 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/24 01:27:55 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define max(a, b) (a < b ? b : a)
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void deep_penetrate(struct s_node *past, struct s_node *present, int seq_count, int *value)
{
	if(present)
	{
		seq_count = (present->value - past->value == 1) ? seq_count + 1 : seq_count;
		*value = max(*value, seq_count);
		deep_penetrate(present, present->left, seq_count, value);
		deep_penetrate(present, present->right, seq_count, value);
	}
}

int	longest_sequence(struct s_node *node)
{
	int value = 1;
	if (!node)
		return 0;
	deep_penetrate(node, node->left, 1, &value);
	deep_penetrate(node, node->right, 1, &value);
	return value;
}

#include <stdlib.h>
#include <stdio.h>
struct s_node *new(int item)
{
	struct s_node *n =(struct s_node *)malloc(sizeof(struct s_node));
	n->value = item;
	n->left = n->right = NULL;
	return n;
}

int main (void)
{
	struct s_node *a = new(10);
	a->left = new(5);
	a->left->left = new(6);
	a->left->right = new(9);
	a->left->left->left = new (7);
	a->left->left->right = new (13);
	printf("The longest consecutive sequence is: %d\n", longest_sequence(a));

	struct s_node *b = new(5);
	b->left = new(6);
	b->right = new(4);
	b->right->right = new(3);
	b->right->right->right = new(2);
	b->right->left = new(9);
	b->right->left->left = new(3);
	b->right->left->right = new(2);
	printf("The longest consecutive sequence is: %d\n", longest_sequence(b));

	struct s_node *c = new(30);
	c->left = new(15);
	c->right = new(41);
	c->left->left = new(61);
	c->right->left = new(80);
	printf("The longest consecutive sequence is: %d\n", longest_sequence(c));

	printf("The longest consecutive sequence is: %d\n", longest_sequence(0));
	return 0;
}