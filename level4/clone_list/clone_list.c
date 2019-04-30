/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:58:53 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/29 17:58:50 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
        int           data;
        struct s_node *next;
        struct s_node *other;
    };
struct s_node *new (int data)
{
    struct s_node *n = (struct s_node *)malloc(sizeof(struct s_node));
    n->data = data;
    n->next = NULL;
    n->other = NULL;
    return n;
}
struct s_node *clone_list(struct s_node *node)
{
    if(node == NULL)
        return 0;
    struct s_node *clone = new(node->data);
    struct s_node *temp_clone = clone;
    struct s_node *n = node;
    
    while(n->next)
    {
        clone->next= new(n->next->data);
        n = n->next;
        clone = clone->next;
    }
    
    n = node;
    clone = temp_clone;
    
    while(n)
    {
        clone->other = n->other;
        n= n->next;
        clone = clone->next; 
    }
    return temp_clone;
}

/********************
  	 TEST MAIN
*******************/

#include <stdio.h>
int main(void)
{
    struct s_node *a = new(1);
    a->next = new(2);
    a->next->next = new(3);
    a->next->next->next = new(4);

    a->other = a->next->next;
    a->next->other = a;
    a->next->next->other = a->next->next;
    a->next->next->next->other = a->next;

    struct s_node *res = clone_list(a);
    while(res)
    {
        printf("%d| ", res->other->data);
        printf("%d->\n", res->data);
        res = res->next;
    }
    res = clone_list(0);
    if(res == 0)
        printf("Mother Fucker!!\n");
    return 0;
}
