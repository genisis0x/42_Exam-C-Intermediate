/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:35:57 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/17 21:45:54 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };

void reverse_tree(struct s_node *root)
{
	struct s_node *temp;
	if (root)
	{
		temp = root->left;
		root->left = root->right;
		root->right = temp;
		reverse_tree(root->left);
		reverse_tree(root->right);
		return ;
	}
	else
		return ;
}
