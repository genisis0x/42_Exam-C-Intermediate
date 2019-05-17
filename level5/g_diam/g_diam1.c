/****************************************** Method 2nd Using Adjacency list ************************************/

#include "g_diam.h"

void ft_put_nbr(int n)
{
    if(n >= 10)
        ft_put_nbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int ft_atoi(char **s)
{
    int nb = 0;
    while(isnum(**s))
    {
        nb = nb * 10 + **s - '0';
        (*s)++;
    }
    if(**s)
        (*s)++;
    return nb;
}

int ft_max(char *s)
{
    int max = 0;
    while(isnum(*s))
    {
        int temp = ft_atoi(&s);
        max = max < temp ? temp : max;
    }
    return max;
}

struct Graph *graph(int V)
{
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    G->vertices = V;
    G->list_array = (struct s_list *)malloc(sizeof(struct s_list) * V);
    for(int i = 0; i < V; i++)
        G->list_array[i].head = NULL;
    return G;
}

struct list_node *add_list_node(int data)
{
    struct list_node *n = (struct list_node *)malloc(sizeof(struct list_node));
    n->data = data;
    n->next = NULL;
    return n;
}

int check(struct s_list *t, int item)
{
    while(t->head)
    {
        if(t->head->data == item)
            return 1;
        t->head = t->head->next;
    }
    return 0;
}


void add_edge(struct Graph *G, int src, int des)
{
    struct s_list temp = G->list_array[src];
    if(!check(&temp, des))
    {
        struct list_node *n = add_list_node(des);
        n->next = G->list_array[src].head;
        G->list_array[src].head = n;
    }
    struct s_list temp1 = G->list_array[des];
    if(!check(&temp1, src))
    {
        struct list_node *n = add_list_node(src);
        n->next = G->list_array[des].head;
        G->list_array[des].head = n;
    }
}

struct Graph *make_graph(int V, char **s)
{
    struct Graph *G = graph(V); 
    while(**s)
    {
        int src = ft_atoi(s);
        int des = ft_atoi(s);
        add_edge(G, src, des);
    }
    return G;
}


// int list_length(struct list_node *h)
// {
//     int c = 0;
//     for(; h; h = h->next)
//         c++;
//     return c;
// }

void solve_graph(struct Graph *G, int max, int visited[], int r, int length, int *long_length)
{
    visited[r] = 1;
    struct list_node *temp = G->list_array[r].head;
    while(temp)
    {
        if (visited[temp->data] == 0)
        {
            *long_length = (*long_length < length + 1) ? length + 1 : *long_length;
            solve_graph(G, max, visited, temp->data, length + 1, long_length);
        }
        temp = temp->next;
            
    }
    visited[r] = 0;
}

// void print_g(struct Graph *g)
// {
//     int v;
//     int flag = 1;
//     for (v = 0; v < g->vertices; ++v) 
//     { 
//         struct list_node *pCrawl = g->list_array[v].head; 
//        if(pCrawl)
//             printf("\n Adjacency list of vertex %d\n head ", v); 
//         while (pCrawl) 
//         { 
//             //printf("\n Adjacency list of vertex %d\n head ", v);
//             printf("-> %d", pCrawl->data); 
//             pCrawl = pCrawl->next;
//             flag = 0;
//         }
//         if(flag == 0)
//         {
//             printf("\n");
//             flag = 1;
//         }
//     } 
// }

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *s = av[1];
        int max = ft_max(s);
        //printf("the max value is: %d\n", max);
        struct Graph *G = make_graph(max + 1, &s);
        int *visited = (int *)malloc(sizeof(int) * (max + 1));
        for(int i = 0; i <= max; i++)
            visited[i] = 0;
        int long_length = 2;
        //print_g(G);
        for(int r = 0; r <= max; r++)
            solve_graph(G, max + 1, visited, r, 1, &long_length);
        ft_put_nbr(long_length);
    }
    write(1, "\n", 1);
    return 0;
}
