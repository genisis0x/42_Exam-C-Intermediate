/********************************** ### Passed Exam Version ### *************************************/
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

struct list_node *add_list_node(int data) // add the node in the Link_List 
{
    struct list_node *n = (struct list_node *)malloc(sizeof(struct list_node));
    n->data = data;
    n->next = NULL;
    return n;
}

int check(struct s_list *t, int item) //check if the list head is already added or not.
{
    while(t->head)
    {
        if(t->head->data == item)
            return 1;
        t->head = t->head->next;
    }
    return 0;
}


void add_edge(struct Graph *G, int src, int des) // add the list in the array of Link_List
{
    struct s_list temp = G->list_array[src];
    if(!check(&temp, des)) //
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

struct Graph *make_graph(int V, char **s) // Graph maker
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

void solve_graph(struct Graph *G, int max, int visited[], int r, int length, int *long_length)
{
    visited[r] = 1;
    struct list_node *temp = G->list_array[r].head; // because if head is directly itireted then there will be a issue in recursion and back tracking, so remove that issue just use temp
    while(temp)
    {
        if (!visited[temp->data]) // if the node is not visited then go and explore the DFS on that node.
        {
            *long_length = (*long_length < length + 1) ? length + 1 : *long_length; // if more than 2 nodes have been seen then updated the len.
            solve_graph(G, max, visited, temp->data, length + 1, long_length);
        }
        temp = temp->next; // jump to next node in the Array of Link_List
            
    }
    visited[r] = 0; // Backtrack
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *s = av[1];
        int max = ft_max(s);
        struct Graph *G = make_graph(max + 1, &s);
        int *visited = (int *)malloc(sizeof(int) * (max + 1));
        for(int i = 0; i <= max; i++)
            visited[i] = 0;
        int long_length = 2;
        for(int r = 0; r <= max; r++)
            solve_graph(G, max + 1, visited, r, 1, &long_length);
        ft_put_nbr(long_length);
    }
    write(1, "\n", 1);
    return 0;
}



// // Good TEST CASES

// // Input1 : 
// "9-23 9-2122 2122-23 2122-24 31-2122 31-41 71-31 8-71 42-71"  
// Output : 
// 6$

// // Input2 :
// "5-56 9-56 7-9 49-9 49-36 7-36 21-7 21-17"
// Output :
// 8$

// // Input3 :
// "0-4 0-3 0-1 0-2 1-2 1-0 1-4 1-5 2-4 3-2 3-4 3-0 3-1 4-0 4-1 4-5 4-2 5-4 5-3 5-1 5-0"
// Output :
// 6$

// // Input4 :
// "0-2 0-3 0-1 1-3 1-2 2-3 3-1 3-0"
// Output :
// 4$

// // Input5 :
// "0-2 0-1 1-3 1-4 1-5 1-2 2-6 2-1 3-2 3-7 3-6 3-1 4-1 4-7 4-6 5-6 5-2 6-5 6-7 6-4 6-3 6-1 6-0 6-2 7-1 7-5 7-3"
// Output :
// 8$

// // Input 6 :
// "0-2 0-1 1-3 1-6 1-0 1-5 2-5 2-6 3-6 3-4 3-5 3-0 3-1 3-2 4-6 5-4 5-2 5-0 5-3 5-6 6-0"
// Output :
// 7$
