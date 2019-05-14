/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 05:31:54 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/14 06:51:27 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define num(x) x >= '0' && x <= '9'

static int ref;

int ft_atoi(char **s)
{
    int num = 0;
    while(num(**s))
    {
        num = num * 10 + **s - '0';
        (*s)++;
    }
    if(**s)
        (*s)++;
    return num;
}


void ft_putnbr(int n)
{
    char c;
    
    if(n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}


int find_max(char **s)
{
    int max = 0, num;
    while(**s)
    {
        num = ft_atoi(s);
        max = num > max ? num : max;
    }
    return max;
}


void longest_path(int max, int arr[max][max], int visited[max], int r, int length)
{
    visited[r] = 1;
    for(int c = 0; c < max; c++)
    {
        if(!visited[c] && arr[r][c])
        {
           if(ref < length + 1)
            ref = length + 1;
           longest_path(max, arr, visited, c, length + 1);
        }
    }
    visited[r] = 0;
}

void solve_matrix(int max, char *s)
{
    int r = max, c = max;
    int arr[r][c];
    int visited[max];
    for(r = 0; r < max; r++)
        for(c = 0; c < max; c++)
        {
            arr[r][c] = 0;
        }
    for(c = 0; c < max; c++)
        visited[c] = 0;
    while(*s)
    {
        r = ft_atoi(&s);
        c = ft_atoi(&s);
        arr[r][c] = 1;
        arr[c][r] = 1;
    }
    ref = 2;
    for(r = 0; r < max; r++)
        longest_path(max, arr, visited, r, 1);
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *s = av[1];
        int max = find_max(&s);
        s = av[1];
        max++;
        solve_matrix(max, s);
        ft_putnbr(ref);
    }
    write(1, "\n", 1);
    return 0;
}
