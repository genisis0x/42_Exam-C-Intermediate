/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 06:47:25 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/09 06:47:25 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/********************* ###### Fully Tested and Passed in Exam ##### ***********************/

struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
};

void help(struct s_node *r, struct s_node *mi, struct s_node *ma)
{
    static struct s_node *p = 0;
    
    if(r->left && r != mi) {help(r->left, mi, ma);}
    
    if(p)
    { p->right = r; r->left = p;}
    
    p = r;
    
    if(r->right && r != ma) {help(r->right, mi, ma);}
    return ;
}

struct s_node *min(struct s_node *l)
{
    while(l->left) {l = l->left;}
    return l;
}

struct s_node *max(struct s_node *v)
{
    while(v->right) {v = v->right;}
    return v;
}

struct s_node *convert_bst(struct s_node *bst)
{
    struct s_node *min_val;
    struct s_node *max_val;
    if(!bst)
        return 0;
    min_val = min(bst);
    max_val = max(bst);
    min_val->left = max_val;
    max_val->right = min_val;
    help(bst, min_val, max_val);
    return min_val;
}

/******************
    TEST MAIN
******************/

#include <stdlib.h>
#include <stdio.h>
struct s_node *new(int d)
{
    struct s_node *n =(struct s_node *)malloc(sizeof(struct s_node));
    n->value =d;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void p(struct s_node *r)
{
    if(!r)
        return ;
    p(r->left);
    printf("%d\n", r->value);
    p(r->right);
}
int main()
{
    struct s_node *a = new(12);
    a->left = new(6);
    a->left->left = new(3);
    a->left->right = new(9);

    a->right = new(18);
    a->right->right = new(20);
    a->right->left = new(15);
    struct s_node *c = a;
    p(c);
    printf("-----------------------------\ncir Doub linklist: \n");
    struct s_node *r = convert_bst(a);
    int i = 0;
    while (i++ < 15)
    {
        printf("%d\n", r->value);
        r = r->right;
    }
}

/* OUTPUT: 3
6
9
12
15
18
20
-----------------------------
cir Doub linklist:
3
6
9
12
15
18
20
3
6
9
12
15
18
20
3
*/


/*********************TEST FUNCTION***************/
// #include <stdio.h>
// void print_in(struct s_node *s)
// {
//     if(!s)
//         return;
//     print_in(s->left);
//     printf("%d\n", s->value);
//     print_in(s->right);
// }
// typedef struct s_node t_n;
// int main()
// {
//     // t_n n1 = {
//     //     .value = 6,
//     //     .left = &(t_n){
//     //         .value = 2,
//     //         .left = &(t_n){
//     //             .value = 1
//     //         },
//     //         .right = &(t_n){
//     //             .value = 4
//     //         }
//     //     },
//     //     .right = &(t_n){
//     //         .value = 8,
//     //         .right = &(t_n){
//     //             .value = 9
//     //         },
//     //         .left = &(t_n){
//     //             .value = 7
//     //         }
//     //     }
//     // };

//     t_n n2 = {
//         .value = 17
//     };
//     print_in(&n2);
//     printf("-------------------------------\n");
//     t_n *r = convert_bst(&n2);
//     int i = -1;
//     while(++i < 15)
//     {
//         printf("%d\n", r->value);
//         r = r->right;
//     }
//     return 0;
// }
