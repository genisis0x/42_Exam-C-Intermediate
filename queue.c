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

#include <stdlib.h>

#include <stdlib.h>

struct  s_node
{
    void            *content;
    struct s_node   *next;
};
struct  s_queue
{
    struct s_node   *first;
    struct s_node   *last;
};

struct s_queue *init(void)
{
	struct s_queue *q = (struct s_queue *)malloc(sizeof(struct s_queue));
	if (!q)
		return NULL;
	q->first = NULL;
	q->last = NULL;
	return(q);
}
void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	
	if (!queue->first)
		queue->first = new;
	if (queue->last)
		queue->last->next = new;
	queue->last = new;
}

void *dequeue(struct s_queue *queue)
{
	void *value = NULL;
	struct s_node *temp = queue->first;
	if (queue->first)
	{
		value = queue->first->content;
		queue->last = (queue->first == queue->last) ? NULL : queue->last;
		queue->first = queue->first->next;
		free(temp);
	}
	return (value);
}
void *peek(struct s_queue *queue)
{
	return (queue->first ? queue->first->content : NULL);
}

int isEmpty(struct s_queue *queue)
{
	return (queue->first ? 0 : 1);
}

/****************
 	TEST_MAIN
****************/

/*
#include <stdio.h>
int main(void)
{
    struct s_queue  *q = init();
    char            *content[][1] = {"1","2","3","4","5"};
    for (int i = 0; i < 5; i++)
    {
        enqueue(q, *content[i]);
		printf("is Empty   : %s\n", (isEmpty(q) ? "yes" : "no"));
    }
	printf("Peek Content : %s\n", peek(q));
    for (int i = 5; i > 0; i--)
    {
        dequeue(q);
		printf("is Empty   : %s\n", (isEmpty(q) ? "yes" : "no"));
    }
	printf("Peek Content : %s\n", peek(q));
    return (0);
}
*/
