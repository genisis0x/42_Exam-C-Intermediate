/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:48:24 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/14 20:48:24 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
struct s_node {
        void          *content;
        struct s_node *next;
    };
    struct s_stack {
        struct s_node *top;
    };

    // 1 . Initilize the stack
    struct s_stack *init(void)
    {
        struct s_stack *stack = malloc(sizeof(struct s_stack));
        stack->top = NULL;
        return stack;
    }

    // 2. Pop Operation
    void *pop(struct s_stack *stack)
    {
        void *item = NULL;
        if (stack->top)
        {
            struct s_node *temp = stack->top;
            item = stack->top->content;
            stack->top = stack->top->next;
            free (temp);
        }
        return item;
    }

    // 3. Push Operation
    void push(struct s_stack *stack, void *content)
    {
        struct s_node *node = malloc(sizeof(struct s_node));
        node->content = content;
        node->next = stack->top;
        stack->top = node;
    }

    // 4. Peek operation return top content of the stack
    void *peek(struct s_stack *stack)
    {
            return stack->top ? stack->top->content : NULL;
    }

    // 5. check if the stack is empty or not.
    int isEmpty(struct s_stack *stack)
    {
        return stack->top ? 0 : 1;
    }

    /***********
      Test Main
    ************/
    /*#include <stdio.h>
    int main (void)
    {
        struct s_stack * s = init();
        printf("The stack is setup\n");
        printf("Is stack Empty %d\n", isEmpty(s));
        puts("Insert Hello");
        push(s, "Hello");
        printf("Is stack Empty %d\n", isEmpty(s));
        printf("Top of stack is %s\n", peek(s));
        puts("Insert World");
        push(s, "World");
        printf("Top of stack is %s\n", peek(s));
        printf("The first element of stack: %s\n", pop(s));
        printf("The second element of stack: %s\n", pop(s));
        printf("Is stack Empty %d\n", isEmpty(s));
        return 0;
    }*/
