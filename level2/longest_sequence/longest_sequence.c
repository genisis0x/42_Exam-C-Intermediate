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

/******************************* #### Passed in Final Exam #### *******************************/

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

#define max(a, b) (a < b ? b : a) 

void util(struct s_node *node, int currlen, int expected, int *res)
{
    if (!node)
        return ;
    if(node->value == expected)
        currlen++;
    else
        currlen = 1;
    *res = max(*res, currlen);
    if(node->left)
        util(node->left, currlen, node->value + 1, res);
    if(node->right)
        util(node->right, currlen, node->value + 1, res);
}


int	longest_sequence(struct s_node *node)
{
    if(!node)
        return 0;
    int res = 0;
    util(node, 0, node->value, &res);
    return res;
}

/************************
	TEST MAIN
************************/


// typedef struct s_node t_node;
// #include <stdio.h>
// int main()
// {
//     t_node node1 = {
//         .value = 10,
//         .left = &(t_node){
//             .value = 5,
//             .left = &(t_node){
//                 .value = 6,
//                 .left = &(t_node){
//                     .value = 7,
//                 }
//             },
//             .right = &(t_node){
//                 .value = 9,
//             }
//         }
//     };

//     printf("The longest sequence 1st is: %d\n", longest_sequence(&node1));

//     t_node node2 = {
//         .value = 5,
//         .left = &(t_node){
//             .value = 6,
//         },
//         .right = &(t_node){
//             .value = 4,
//             .left = &(t_node){
//                 .value = 9,
//                 .left = &(t_node){
//                     .value = 3,
//                 },
//                 .right = &(t_node){
//                     .value = 2,
//                 }
//             },
//             .right = &(t_node){
//                 .value = 3,
//                 .right = &(t_node){
//                     .value = 2,
//                 }
//             }
//         }
//     };
//     printf("The longest sequence 2nd is: %d\n", longest_sequence(&node2));

//     t_node node3 ={
//         .value = 10,
//         .left = &(t_node){
//             .value = 15,
//             .left = &(t_node){
//                 .value = 61,
//             }
//         },
//         .right = &(t_node){
//             .value = 41,
//             .left = &(t_node){
//                 .value = 80,
//             }
//         }
//     };
//     printf("The longest sequence 3rd is: %d\n", longest_sequence(&node3));
//     printf("The longest sequence 4th is: %d\n", longest_sequence(0));
//     return 0;
// }
