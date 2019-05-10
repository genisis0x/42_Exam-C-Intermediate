/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 04:02:57 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/10 07:41:37 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int len(char *s)
{
    int c = 0;
    for( ; *s; s++)
        c++;
    return c;
}

char *ft_str_max(char *s1, char *s2)
{
    int l1 = len(s1);
    int l2 = len(s2);
    int **arr = (int **)malloc(sizeof(int *) * l1 + 1);

    for(int i = 0; i <= l1; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * l2 + 1);
    }
    
    for(int i = 0 ; i <= l1; i++)
        for(int j = 0; j <= l2; j++)
            arr[i][j] = 0;

    int i_idx, j_idx, start, max_len = 0;
    for(int i = 1 ; i <= l1; i++)
        for(int j = 1; j <= l2; j++)
        {
            if(s1[i - 1] == s2[j -1])
            {
                arr[i][j] = 1 + arr[i -1][j -1];
                if(max_len < arr[i][j])
                {
                    max_len = arr[i][j];
                    i_idx = i;
                    j_idx = j;
                }
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    
    if (max_len == 0)
    {
        char *r = (char *)malloc(sizeof(char) * 1);
        r[0] = '\0';
        return r;
    }
    
    for(int i = i_idx, j = j_idx; arr[i][j] > 0; i--, j--)
    {
        start = i - 1;
    }
    
    char *r = (char *)malloc(sizeof(char) * (max_len + 1));
    for (int i = start , j = 0; i < start + max_len; i++, j++)
    {
        r[j] = s1[i];
    }
    r[max_len] = '\0';
    free(arr);
    return r;
}

int main(int ac, char **av)
{
    if(ac >= 2)
    {
        char *res = av[1];
        if(ac == 2)
        {
            while(*res)
            {
                write(1, res, 1);
                res++;
            }
        }
        else
        {
            int i = 2;
            while( i < ac)
            {
                res = ft_str_max(res, av[i]);
                if(len(res) == 0)
                    break;
                i++;
            }
            while(*res)
            {
                write(1, res, 1);
                res++;
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}

//