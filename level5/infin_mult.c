/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:12:36 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/28 22:26:27 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


int len(char *s)
{
    int c = 0;
    while(*s)
    {
        s++;
        c++;
    }
    return c;
}


char *ft_strcpy(char *s)
{
    int l = len(s);
    int i = 0; 
    char *r = (char *)malloc(sizeof(char) * (l + 1));
    while(*s)
    {
        if(*s == '-')
        {
            s++;
        }
        else
        {
            r[i++] = *s;
            s++;
        }
    }
    return r;
}


void swap(char **s1, char **s2)
{
    char *t = *s1;
    *s1 = *s2;
    *s2 = t;
}


char *infin_mult(char *s1 , char *s2)
{
    int l1 = len(s1);
    int l2 = len(s2);
    char *r = (char *)malloc(sizeof(char) *(l1 * l2));
    
    int i = 0;
    int carry = 0;

    if(l1 > l2)
    {
        swap(&s1, &s2);
        int temp = l1;
        l1 = l2;
        l2 = temp;
    }
    while()
    {
        
    }
    return r;
}



int main (int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        char *s1 = av[1];
        char *s2 = av[2];
        if((s1[i] == '-' && s2[i] == '-') && (s1[i] != '-' && s2[i] != '-'))
        {
            s1 = ft_strcpy(s1);
            s2 = ft_strcpy(s2);
            char *res = infin_mult(s1, s2);
            while (res[i])
            {
                write(1, &res[i++], 1);
            }
        }
        else
        {
            write(1, "-", 1);
            s1 = ft_strcpy(s1);
            s2 = ft_strcpy(s2);
            char *res = infin_mult(s1, s2);
            while (res[i])
            {
                write(1, &res[i++], 1);
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}
