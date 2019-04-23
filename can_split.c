/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:48:11 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/23 00:39:33 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

int total_nodes(struct s_node *root)
{
	if (!root)
		return 0;
	return (1 + total_nodes(root->left) + total_nodes(root->right));
}

int is_split (struct s_node *r, int *split_num, int t_nodes)
{
	if (!r)
		return 0;
	int temp = is_split(r->left, split_num, t_nodes) + is_split(r->right, split_num, t_nodes) + 1;
	if (t_nodes - temp == temp)
		*split_num = 1;
	return temp;
}
int can_split(struct s_node *n)
{
	int t_nodes = total_nodes(n);
	if (nodes % 2)
		return 0;
	int split_num = 0;
	is_split(n, &split_num, t_nodes);
	return split_num;
}


/************
  Test Main
************/

#include <stdlib.h>
#include <stdio.h>
struct s_node* b(int v) {
    struct s_node* new = malloc(sizeof(struct s_node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {
    struct s_node* ex1 = b(28);
    ex1->left = b(51);
    ex1->left->left = b(26);
    ex1->left->left->left = b(76);
    ex1->left->left->right = b(13);
    ex1->left->right = b(48);

    printf("%d\n", can_split(ex1));

   struct s_node* ex2 = b(30);
    ex2->left = b(15);
    ex2->left->left = b(61);
    ex2->right = b(41);
    ex2->right->right = b(80);

    printf("%d\n", can_split(ex2));


    struct s_node* ex3 = b(10);
    ex3->left = b(12);

    printf("%d\n", can_split(ex3));

    struct s_node* ex4 = b(5);
    ex4->left = b(1);
    ex4->right = b(6);
    ex4->right->left = b(7);
    ex4->right->left->left = b(3);
    ex4->right->left->left = b(2);
    ex4->right->right = b(4);
    ex4->right->right->right = b(8);

    printf("%d\n", can_split(ex4));
    return 0;
}
