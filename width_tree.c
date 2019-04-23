/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 01:12:09 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/23 01:29:25 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define max(a,b) (a < b ? b : a)
#include <stdio.h>
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int longest(struct s_node *node)
{
	if (!node)
		return 0;
	return max(longest(node->left), longest(node->right)) + 1;
}
int	width_tree(struct s_node *n)
{
	if (!n)
		return 0;
	int width = longest(n->left) + longest(n->right) + 1;
	return max(max(width_tree(n->left), width_tree(n->right)), width);
}

/************
  Test Main
************/

#include <stdio.h>
#include <stdlib.h>
struct s_node *b(int v)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->value = v;
	new->left = new->right = 0;
	return new;
}
int main()
{
	
	struct s_node *r = b(1);

	r->left = b(2);
	r->left->left = b(3);
	r->left->right = b(4);
	r->left->right->left = b(6);

	r->right = b(5);
	r->right->left = b(7);
	r->right->right = b(8);

	printf("%d\n", width_tree(r));

	struct s_node *a = b(1);

	a->left = b(2);
	a->left->left = b(4);
	a->left->left->left = b(5);
	a->left->left->left->right = b(8);

	a->left->left->right = b(6);
	a->left->right = b(7);
	a->left->right->left = b(9);
	a->left->right->left->left = b(11);
	a->left->right->left->right = b(12);

	a->left->right->right = b(10);
	a->left->right->right->right = b(13);

	a->right = b(3);
	printf("%d\n", width_tree(a));

	struct s_node *c = b(10);
	c->right = b(12);
	printf("%d\n", width_tree(c));

	struct s_node *d = b(25);
	d->left = b(33);
	d->left->left = b(12);
	d->left->right = b(9);
	d->left->right->left = b(3);
	printf("%d\n", width_tree(d));

	struct s_node *e = b(10);
	printf("%d\n", width_tree(e));

	return 0;
}