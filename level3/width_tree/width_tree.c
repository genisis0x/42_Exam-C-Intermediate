/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 01:12:09 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/23 01:30:15 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/********************************* #### Passed in Final Exam #### *************************/ 

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

#define max(a, b) (a < b ? b : a)


int long_util(struct s_node *n)
{
	if(!n)
		return 0;
	else
		return ( 1 + max(long_util(n->left), long_util(n->right)));
}

int	width_tree(struct s_node *n)
{
	if(!n)
		return 0;
	else	
	{
		int lheight = long_util(n->left);
		int rheight = long_util(n->right);
		return max(max(width_tree(n->left), width_tree(n->right)), 1 + lheight + rheight);
	}
}

// typedef struct s_node t_n;
// #include <stdio.h>
// int main ()
// {
// 	t_n n1 = {
// 		.value = 1,
// 		.left = &(t_n){
// 			.value = 2,
// 			.left = &(t_n){
// 				.value = 3
// 			},
// 			.right = &(t_n){
// 				.value = 4,
// 				.left = &(t_n){
// 					.value = 6
// 				}
// 			}
// 		},
// 		.right = &(t_n){
// 			.value = 5,
// 			.left = &(t_n){
// 				.value = 7
// 			},
// 			.right = &(t_n){
// 				.value = 8
// 			}
// 		}
// 	};
// 	printf("The 1st width of the tree is: %d\n", width_tree(&n1));

// 	t_n n2 = {
// 		.value = 1,
// 		.left = &(t_n){
// 			.value = 2,
// 			.left = &(t_n){
// 				.value = 4,
// 				.left =&(t_n){
// 					.value = 5,
// 					.right = &(t_n){
// 						.value = 8
// 					}
// 				},
// 			.right = &(t_n){
// 				.value = 6
// 			}
// 		},
// 		.right = &(t_n){
// 			.value = 7,
// 			.left = &(t_n){
// 				.value = 9,
// 				.left = &(t_n){
// 					.value = 11
// 				},
// 				.right = &(t_n){
// 					.value = 12
// 				}
// 			},
// 			.right = &(t_n){
// 				.value = 10,
// 				.right = &(t_n){
// 					.value = 13
// 				}
// 			}
// 		}
// 	},
// 	.right = &(t_n){
// 		.value = 3
// 		}
// 	};
// 	printf("The 2nd width of the tree is: %d\n", width_tree(&n2));

// 	t_n n3 = {
// 		.value = 10,
// 		.right = &(t_n){
// 			.value = 12
// 		}
// 	};
// 	printf("The 3rd width of the tree is: %d\n", width_tree(&n3));

// 	t_n n4 = {
// 		.value = 25,
// 		.left = &(t_n){
// 			.value = 35,
// 			.left = &(t_n){
// 				.value = 12
// 			},
// 			.right = &(t_n){
// 				.value = 9,
// 				.left = &(t_n){
// 					.value = 3
// 				}
// 			}
// 		}
// 	};
// 	printf("The 4th width of the tree is: %d\n", width_tree(&n4));

// 	t_n n5 ={
// 		.value = 10
// 	};
// 	printf("The 5th width of the tree is: %d\n", width_tree(&n5));

// 	return 0;
// }
