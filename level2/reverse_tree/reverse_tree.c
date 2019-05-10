/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:35:57 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/23 18:51:32 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************** #### PASSED FINAL EXAM #### *************************************/

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };
void reverse_tree(struct s_node *root)
{
	if (!root)
		return ;
	else
	{
		struct s_node *temp = root->left;
		root->left = root->right;
		root->right = temp;
		if(root->left)
			reverse_tree(root->left);
		if(root->right)
			reverse_tree(root->right);
	}
}

