/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 01:54:39 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/07 02:01:46 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
    int           data;
    struct s_node *next;
    struct s_node *other;
};

struct s_node *clone_list(struct s_node *node) {

    if (!node)
        return 0;

    struct s_node *original = node;
    struct s_node *temp;

    // Clone list in-between original
    while (original) {
        temp = original->next;
        original->next = (struct s_node *)malloc(sizeof(struct s_node));
        original->next->data = original->data;
        original->next->other = 0;
        original->next->next = temp;
        original = temp;
    }

    original = node;

    // Set other pointers for cloned list
    while (original) {
        if (original->other)
            original->next->other = original->other->next;
        if (original->next)
            original = original->next->next;
        else
            break;
    }

    original = node;
    struct s_node* copy = node->next;
    struct s_node* copyHead = copy;

    while (original && copy) {
        if (original->next)
            original->next = original->next->next;
        if (copy->next)
            copy->next = copy->next->next;
        original = original->next;
        copy = copy->next;
    }
    return copyHead;
}

/************
  Test Main
************/

/*
#include <stdio.h>
struct s_node *b(int v) {
    struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
    new->data = v;
    new->next = 0;
    new->other = 0;
    return new;
}
int main() {
    struct s_node *a = b(1);
    a->next = b(2);
    a->next->next = b(3);
    a->next->next->next = b(4);
    a->next->next->next->next = b(5);
    a->next->next->next->next->next = b(6);
    a->next->next->next->next->next->next = b(7);

    struct s_node* a2 = a->next;
    struct s_node* a3 = a2->next;
    struct s_node* a4 = a3->next;
    struct s_node* a5 = a4->next;
    struct s_node* a6 = a5->next;
    struct s_node* a7 = a6->next;

    a2->other = a7;
    a3->other = a;
    a5->other = a5;
    a7->other = a4;

    struct s_node *clone = clone_list(a);
    struct s_node *original = a;
    puts("Original:");
    while (original) {
        printf("Val: %d | Other: %d\n", original->data, original->other ? original->other->data : -1);
        original = original->next;
    }
    puts("Clone:");
    while (clone) {
        printf("Val: %d | Other: %d\n", clone->data, clone->other ? clone->other->data : -1);
        clone = clone->next;
    }
    return 0;
}*/
