/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 09:19:16 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/12 09:34:23 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
    int           data;
    struct s_node *next;
    struct s_node *other;
};

struct s_node *new(int item)
{
    struct s_node *r =(struct s_node *)malloc(sizeof(struct s_node));
    r->data = item;
    r->next = r->other = NULL;
    return r;
}

struct s_node *clone_list(struct s_node *node)
{
    struct s_node *curr = node, *temp;

    // Clone list in-between the original List
    while(curr)
    {
        temp = curr->next;
        curr->next = new(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = node;

     // Set other pointers for cloned list from getting reference to original list 
    while(curr)
    {
        if(curr->next)
            curr->next->other = curr->other ? curr->other->next : curr->other;
        curr = curr->next ? curr->next->next: curr->next;
    }
    struct s_node *org = node, *copy = node->next;

    temp = copy;
    // Bifurcate both the list and return the cloned list.
    while(copy && org)
    {
        org->next = org->next ? org->next->next : org->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        copy = copy->next;
        org = org->next;
    }
    return temp;

}

/************
  Test Main
************/


// #include <stdio.h>
// struct s_node *b(int v) {
//     struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
//     new->data = v;
//     new->next = 0;
//     new->other = 0;
//     return new;
// }
// int main() {
//     struct s_node *a = b(1);
//     a->next = b(2);
//     a->next->next = b(3);
//     a->next->next->next = b(4);
//     a->next->next->next->next = b(5);
//     a->next->next->next->next->next = b(6);
//     a->next->next->next->next->next->next = b(7);

//     struct s_node* a2 = a->next;
//     struct s_node* a3 = a2->next;
//     struct s_node* a4 = a3->next;
//     struct s_node* a5 = a4->next;
//     struct s_node* a6 = a5->next;
//     struct s_node* a7 = a6->next;

//     a2->other = a7;
//     a3->other = a;
//     a5->other = a5;
//     a7->other = a4;

//     struct s_node *clone = clone_list(a);
//     struct s_node *original = a;
//     puts("Original:");
//     while (original) {
//         printf("Val: %d | Other: %d\n", original->data, original->other ? original->other->data : -1);
//         original = original->next;
//     }
//     puts("Clone:");
//     while (clone) {
//         printf("Val: %d | Other: %d\n", clone->data, clone->other ? clone->other->data : -1);
//         clone = clone->next;
//     }
//     return 0;
// }
