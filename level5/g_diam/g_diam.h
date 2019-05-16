# ifndef G_DIAM_H
# define G_DIAM_H
#include <stdio.h>
struct list_node
{
    int data;
    struct list_node *next;
};

struct s_list
{
    struct list_node *head;
};

struct Graph
{
    int vertices;
    struct s_list *list_array;
};

#include <stdlib.h>
#include <unistd.h>
#define isnum(x) x >= '0' && x <= '9'
#endif
