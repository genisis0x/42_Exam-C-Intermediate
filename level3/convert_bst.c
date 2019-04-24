/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:23:53 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/23 20:24:53 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };

void bst_recursion(struct s_node *root, struct s_node *min, struct s_node *max)
{
	if(!root)
		return ;
	static struct s_node *prev = 0;
	
	// 1st step
	if (root != min)
		bst_recursion(root->left, min, max); 
	
	// 2nd step
	if(prev)
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	
	// 3rd Step
	if (root != max)
		bst_recursion(root->right, min, max);
}

struct s_node *bst_min(struct s_node *r)
{
	while(r->left)
		r = r->left;
	return r;
}
struct s_node *bst_max(struct s_node *r)
{
	while (r->right)
		r = r->right;
	return r;
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *min_val;
	struct s_node *max_val;
	if (!bst)
		return (bst);
	min_val = bst_min(bst);
	max_val = bst_max(bst);
	min_val->left = max_val;
	max_val->right = min_val;
	bst_recursion(bst, min_val, max_val);
	return min_val;
}

/****************
	TEST MAIN
****************/

#include <stdlib.h>
#include <stdio.h>
struct s_node *b(int v)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->value = v;
	new->left = new->right = 0;
	return new;
}
int main()
{
	struct s_node *r = b(8);
	r->left = b(4);
	r->left->left = b(2);
	r->left->left->left = b(1);
	r->left->left->right = b(3);

	r->left->right = b(6);
	r->left->right->left = b(5);
	r->left->right->right = b(7);

	r->right = b(12);
	r->right->left = b(10);
	r->right->left->left = b(9);
	r->right->left->right = b(11);

	r->right->right = b(14);
	r->right->right->left = b(13);
	r->right->right->right = b(15);

	r = convert_bst(r);
	for (int i = 0; i < 15; i++)
	{
		printf("%d\n", r->value);
		r = r->right;
	}
	for (int i = 0; i < 17; i++)
	{
		printf("%d\n", r->value);
		r = r->left;
	}
}
