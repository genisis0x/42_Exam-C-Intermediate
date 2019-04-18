#include <unistd.h>
#include <stdlib.h>
typedef struct s_list
{
    char *str;
    int len;
    struct s_list *next;
    
} t_list;

t_list *head = NULL;

int is_alphanumeric(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ('0' <= c && c <= '9'));
}
int is_space_tab(char c)
{
    return (c == ' ' || c == '\t');
}

int str_len(char *s)
{
    int count = 0;
    while(*s)
    {
        count++;
        s++;
    }
    return count;
}

t_list *new(int a, char *s)
{
    t_list *node;
     if (!(node = (t_list *)malloc(sizeof(t_list))))
    {
        return NULL;
    }
    node->str = s;
    node->len = a;
    node->next = NULL;
    return node;
}

void reverse_list(t_list *previous, t_list **current, t_list *future)
{
    t_list *current1 = *current;
    while(current1)
    {
        future = current1->next;
        current1->next = previous;
        previous = current1;
        current1 = future;
    }
    *current = previous;
}


void push(t_list *node)
{
    if(!head)
    {
        head = node;
        return ;
    }
    else
    {
        node->next = head;
        head = node;
        return ;
    }
}

char *str_trim(char * s, int start, int len)
{
    char *res = (char *)malloc(sizeof(char));
    int r = 0;
    while (r < len)
    {
        res[r++] = s[start++];
    }
    res[r] = '\0';
    return res;
}

int ft_strcmp(char *a, char *b)
{
    char c, d;
    while(*a && *b)
    {
        c = *a;
        d = *b;
        if(c != d)
        {
            if ((c >= 'A' && c <= 'Z') || (d >= 'B' && d <= 'Z'))
            {
                if (c >= 'A' && c <= 'Z')
                {
                    c = c + 32;
                }
                if (d >= 'A' && d <= 'Z')
                {
                    d = d + 32;
                }
            }
        }
            if((c - d) > 0)
            {
                return 1;
            }
            else if (c - d < 0)
            {
                return -1;
            }
        a++;
        b++;
    }
    return 0;
}

void swap(t_list *a, t_list *b)
{
    char *temp1;
    if (a->len != b->len)
    {
        int temp  = a->len;
        a->len = b->len;
        b->len = temp;
        temp1 = a->str;
        a->str = b->str;
        b->str = temp1;
    }
    else
    {
        if (ft_strcmp(a->str, b->str) == 1)
        {
            temp1 = a->str;
            a->str = b->str;
            b->str = temp1;
        }
    }
}

void sort_int_list(t_list *lst)
{
    t_list *traverse = lst;
    t_list *future;
    while(traverse)
    {
        future = traverse->next;
        while(future)
        {
            if (str_len(traverse->str) >= str_len(future->str))
            {
                swap(traverse, future);
            }
            future = future->next;
        }
        traverse = traverse->next;
    }
}

void ft_print_list(t_list *node)
{
    t_list *temp;
    while(node)
    {
        temp = node;
        char *sr = node->str;
        while(*sr)
        {
            write(1, sr, 1);
            sr++;
        }
        if (node->next && (node->len != node->next->len))
        {
            write(1, "\n", 1);
        }
        if (!node->next)
        {
            write(1, "\n", 1);
            node = node->next;
            free(temp);
            return ;
        }
        else if (node->next && (node->len == node->next->len))
        {
            write(1, " ", 1);
        }
        node = node->next;
        free(temp);
    }
}

int main (int ac, char **av)
{
    int i = 0, j = 0, start = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            while(is_space_tab(av[1][i]))
            {
                i++;
            }
            start = i;
            j = 0;
            while(!is_space_tab(av[1][i]) && is_alphanumeric(av[1][i]))
            {
                j++;
                i++;
            }
            char *node = str_trim(av[1], start, j);
            push(new (j, node));
        }
        reverse_list(NULL, &head, NULL);
        sort_int_list(head);
        ft_print_list(head);
    }
    else
    {
        write(1, "\n", 1);
    }
    return 0;
}