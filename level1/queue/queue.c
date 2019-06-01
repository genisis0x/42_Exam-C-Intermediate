/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:26:21 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/18 20:52:28 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************ #### Passed Final Exam #### *************************************/

#include <stdlib.h>

struct s_node {
        void *content;
        struct s_node *next;
    };

 struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };

struct s_queue *init(void)
{
	struct s_queue *new = (struct s_queue *)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return new;
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
	node->content = content;
	node->next = NULL;
	if (!queue->first)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}
}

void *dequeue(struct s_queue *queue)
{
	void *ele = NULL;
	if (queue->first)
	{
		struct s_node *temp = queue->first;
		ele = queue->first->content;
		queue->last = (queue->first == queue->last) ? NULL : queue->last;
		queue->first = queue->first->next;
		free(temp);
	}
	return ele;
}

void *peek(struct s_queue *queue)
{
	return queue->first ? queue->first->content : NULL;
}

int isEmpty(struct s_queue *queue)
{
	return queue->first ? 0 : 1;
}

/****************
 	TEST_MAIN
****************/

/*
#include <stdio.h>

int main(void)
{
    struct s_queue  *q = init();
	printf("The Queue has been setup..!!\n");
	printf("The Queue is empty: %s\n", isEmpty(q) ? "YES" : "NO");
	puts("Putting Hello");
	enqueue(q, "Hello");
	printf("The Queue is empty: %s\n", isEmpty(q) ? "YES" : "NO");
	printf("The peek of the Queue is -> %s\n", peek(q) );
	puts("Putting World!!");
	enqueue(q, "World!!");
	printf("The peek of the Queue is -> %s\n", peek(q));
	printf("The Queue is empty: %s\n", isEmpty(q) ? "YES" : "NO");
	printf("The first dequeue operation Removes -> %s\n", dequeue(q));
	printf("The Second dequeue operation Removes ->  %s\n", dequeue(q));
	printf("The Third dequeue operation Removes -> %s\n", dequeue(q));
	printf("The Queue is empty: %s\n", isEmpty(q) ? "YES" : "NO");
	printf("The peek of the Queue is -> %s\n", peek(q));
	return 0;
}
*/

/*
Expected Output:

The Queue has been setup..!!
The Queue is empty: YES
Putting Hello
The Queue is empty: NO
The peek of the Queue is -> Hello
Putting World!!
The peek of the Queue is -> Hello
The Queue is empty: NO
The first dequeue operation Removes -> Hello
The Second dequeue operation Removes ->  World!!
The Third dequeue operation Removes -> (null)
The Queue is empty: YES
The peek of the Queue is -> (null)
*/
