/************************** #### PASSED FINAL EXAM #### ***************************/

#include <stdio.h>

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };


void perimeter_left(struct s_node *root)
{
	if(!root) return;
	
	if(root->left || root->right) printf(" %d", root->value); 
	
	if(root->left) perimeter_left(root->left);
}

void perimeter_right(struct s_node *root)
{
	if(!root) return;
	
	if (root->right) perimeter_right(root->right);
	
	if(root->right || root->left) printf(" %d", root->value);
}
void perimeter_node(struct s_node *root)
{
	if (root->left) perimeter_node(root->left);
	
	if(root->right) perimeter_node(root->right);
	
	if(!root->left && !root->right) printf(" %d", root->value);
}

void perimeter(struct s_node *root)
{
	if(!root) return;
	
	if (root) printf("%d", root->value);

	if(root->left) {perimeter_left(root->left); perimeter_node(root->left);}

	if(root->right) {perimeter_node(root->right); perimeter_right(root->right);}

	printf("\n");
}

/************************
	TEST MAIN
************************/

#include <stdlib.h>
#include "stdio.h"
#include "stdlib.h"

struct s_node *new(int item)
{
	struct s_node *n = (struct s_node *)malloc(sizeof(struct s_node));
	n->value = item;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int main (void)
{
	struct s_node *node = new(92);

	node->left = new(85);
	node->right = new(26);

	node->left->left = new(79);

	//node->left->left->left = new(200);
	//node->left->left->left->left = new(300);
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
	node->right->right->left->left->right->left = new(58);

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

	node->right->right->right->right->right = new(51);
	//node->right->right->right->right->right->left = new(100);

	perimeter(node);
	return 0;
}

/*
t_node root = {
		.value = 92,
		.left = &(t_node){
			.value = 85,
			.left = &(t_node){
				.value = 79,
				.right = &(t_node){
					.value = 10,
					.left = &(t_node){
						.value = 39,
						.left = &(t_node){
							.value = 35,
							.left = &(t_node){.value = 96}
						}
					}
				}
			}
		},
		.right = &(t_node){
			.value = 26,
			.right = &(t_node){
				.value = 64,
				.left = &(t_node){
					.value = 40,
					.left = &(t_node){
						.value = 88,
						.left = &(t_node){
							.value = 12,
							.left = &(t_node){.value = 58}
						},
						.right = &(t_node){
							.value = 55,
							.left = &(t_node){.value = 58},
							.right = &(t_node){.value = 41}
						}
					},
					.right = &(t_node){
						.value = 10,
						.left = &(t_node){
							.value = 52,
							.left = &(t_node){.value = 22},
							.right = &(t_node){.value = 35}
						},
						.right = &(t_node){
							.value = 87,
							.right = &(t_node){.value = 31}
						}
					}
				},
				.right = &(t_node){
					.value = 78,
					.left = &(t_node){
						.value = 2,
						.left = &(t_node){
							.value = 33,
							.right = &(t_node){.value = 55}
						},
						.right = &(t_node){
							.value = 11,
							.left = &(t_node){.value = 99}
						}
					},
					.right = &(t_node){
						.value = 85,
						.right = &(t_node){.value = 51}
					}
				}
			}
		}
	};
	perimeter(&root);
	printf("\n");
*/
