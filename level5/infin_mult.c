/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:12:36 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/28 23:12:23 by maparmar         ###   ########.fr       */
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
    if (*s1 == '0' || *s2 == '0')
        return "0";
    
    int len1 = len(s1);
    int len2 = len(s2);
    int len = len1 + len2;
    
    int *arr = (int *)malloc(sizeof(int) * len); //the number of digits of the result - len is the top;
    
    for(int i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
    
    for (int i = len1 - 1; i > -1; i--)
        for (int j = len2 - 1; j > -1; j--)
            arr[i + j + 1] += (s1[i] - '0') * (s2[j] - '0'); //collect result of each position;
    for (int i = len - 1; i > 0; i--)                        //restore the carry for each position and get the final result;
    {
        arr[i - 1] += arr[i] / 10;
        arr[i] %= 10;
    }
    char *s = (char *)malloc(sizeof(char) * (len + 1)); //converting the digits result to string;
    int index = 0;
    int i = 0;
    if (arr[i] == 0)
        i++; //in case the zero position has no carry, if it does, ignore it;
    while (i < len)
        s[index++] = arr[i++] + '0';
    s[index] = '\0';
    return s;
}

int main (int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        char *s1 = av[1];
        char *s2 = av[2];
        if((s1[i] == '-' && s2[i] == '-') || (s1[i] != '-' && s2[i] != '-'))
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
