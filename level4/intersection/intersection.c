/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:55:22 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/29 14:40:50 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************### Passed Exam Version ###*****************************************/

struct s_node {
        void *content;
        struct s_node *next;
    };

int len_list(struct s_node *list)
{
	int c = 0;
	for (; list; list = list->next)
		c++;
	return c;
}

void swap(struct s_node **l1, struct s_node **l2)
{
	struct s_node *temp = *l1;
	*l1 = *l2;
	*l2 = temp;
}

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	int len1 = len_list(lst1);
	int len2 = len_list(lst2);
	int d = len2 -len1;
	int j = 0;

	if(len1 > len2)
	{
		swap(&lst1, &lst2);
		d = -d;
		int temp = len1;
		len1 = len2;
		len2 = temp;
	}
	while (j < d)
	{
		lst2 = lst2->next;
		j++;
	}
	while (lst2 && lst1)
	{
		if(lst1 == lst2)
		{
			return lst1;
		}
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return 0;
}

/*****************
 	TEST MAIN
******************/

#include <stdio.h>
#include <stdlib.h>
struct s_node* b(void* v) {
	struct s_node* new = malloc(sizeof(struct s_node));
	new->content = v;
	new->next = 0;
	return new;
}
int main() {
	struct s_node* a = b("a");
	a->next = b("b");
	a->next->next = b("c");
	a->next->next->next = b("d");
	a->next->next->next->next = b("e");
	a->next->next->next->next->next = b("f");

	struct s_node* c = b("g");
	c->next = b("h");
	c->next->next = b("i");
	c->next->next->next = b("j");
	c->next->next->next->next = b("k");
	c->next->next->next->next->next = b("l");

	struct s_node* ret = intersection(a, c);
	printf("%s\n", ret ? ret->content : 0);

	c->next->next = a->next->next->next;
	ret = intersection(a, c);
	printf("%s\n", ret ? ret->content : 0);

	return 0;
}

//Expected Output -> (null) & d
