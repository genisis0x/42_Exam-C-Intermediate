/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 05:31:54 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/16 17:35:07 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/********************************** ### Passed Exam Version ### *************************************/

/****************************************** Method 1st Using Adjacency Matrix ************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
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


void longest_path(int max, uint8_t arr[max][max], uint8_t visited[max], int r, int length)
{
    visited[r] = 1;
    for(int c = 0; c < max; c++)
    {
        if(!visited[c] && arr[r][c])
        {
            
            if (ref < length + 1)
            {
                ref = (ref < length + 1) ? length + 1 : ref;
                printf("The path is : %d\n", r);
            }
            longest_path(max, arr, visited, c, length + 1);
        }
    }
    visited[r] = 0;
}

void solve_matrix(int max, char *s)
{
    int r = max, c = max;
    uint8_t arr[max][max];
    uint8_t visited[max];
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
        solve_matrix(max + 1, s);
        ft_putnbr(ref);
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

