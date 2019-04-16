/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:17:15 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/16 13:37:26 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };


void perimeter_left(struct s_node *root)
{
	if (root->left)
	{
		printf(" %d", root->value);
		perimeter_left(root->left);
	}
}


void perimeter_right(struct s_node *root)
{
	if (root->right)
	{
		perimeter_right(root->right);
		printf(" %d", root->value);
	}
}

void perimeter_node(struct s_node *root)
{
	if (root->left)
		perimeter_node(root->left);
	if(root->right)
		perimeter_node(root->right);
	if(!root->left && !root->right)
		printf(" %d", root->value);
}

void perimeter(struct s_node *root)
{
	if (root)
		printf("%d", root->value);
	if (root->left)
	{
		perimeter_left(root->left);
		perimeter_node(root->left);
	}
	if(root->right)
	{
		perimeter_node(root->right);
		perimeter_right(root->right);
	}
	printf("\n");
}


#include <stdio.h>
#include <stdlib.h>


struct s_node *new(int item)
{
	struct s_node *n = (struct s_node *)malloc(sizeof(struct s_node));
	n->value = item;
	n->left = NULL;
	n->right = NULL;
	return n;
}
/*
int main (void)
{
	struct s_node *node = new(92);

	node->left = new(85);
	node->right = new(26);

	node->left->left = new(79);

	node->left->left->right = new(10);

	node->left->left->right->left = new(39);

	node->left->left->right->left->left = new(35);

	node->left->left->right->left->left->left = new(96);

	node->right->right = new(64);

	node->right->right->left = new(40);
	node->right->right->right = new(78);

	node->right->right->left->left = new(88);
	node->right->right->left->right = new(10);

	node->right->right->left->left->left = new(12);
	node->right->right->left->left->right = new(55);

	node->right->right->left->left->left->left = new(58);
	node->right->right->left->left->right->right = new(41);

	node->right->right->left->right->left = new(52);
	node->right->right->left->right->right = new(87);

	node->right->right->left->right->left->left = new(22);
	node->right->right->left->right->left->right = new(35);

	node->right->right->left->right->right->right = new(31);

	node->right->right->right->left = new(2);
	node->right->right->right->right = new(85);

	node->right->right->right->left->left = new(33);
	node->right->right->right->left->right = new(11);

	node->right->right->right->left->left->right = new(55);

	node->right->right->right->left->right->left = new(99);

	node->right->right->right->right = new(85);

	node->right->right->right->right->right = new(51);

	perimeter(node);
	return 0;
}
*/
#include <stdlib.h>
struct s_node *b(int v) {
    struct s_node *new = malloc(sizeof(struct s_node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {

    struct s_node *r = b(92);

    r->left = b(85);
    r->left->left = b(79);
    r->left->right = b(10);
    r->left->right->left = b(39);
    r->left->right->left->left = b(35);
    r->left->right->left->left->left = b(96);

    r->right = b(26);
    r->right->right = b(64);
    r->right->right->left = b(40);
    r->right->right->left->left = b(88);
    r->right->right->left->left->left = b(12);
    r->right->right->left->left->left->left = b(58);

    r->right->right->left->left->right = b(55);
    r->right->right->left->left->right->left = b(58);
    r->right->right->left->left->right->right = b(41);

    r->right->right->left->right = b(10);
    r->right->right->left->right->left = b(52);
    r->right->right->left->right->left->left = b(22);
    r->right->right->left->right->left->right = b(35);

    r->right->right->left->right->right = b(87);
    r->right->right->left->right->right->right = b(31);


    r->right->right->right = b(78);
    r->right->right->right->left = b(2);
    r->right->right->right->left->left = b(33);
    r->right->right->right->left->left->right = b(55);

    r->right->right->right->left->right = b(11);
    r->right->right->right->left->right->left = b(99);

    r->right->right->right->right = b(85);
    r->right->right->right->right->right = b(51);

    perimeter(r);
    return 0;
}

