/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 20:06:01 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/28 20:06:22 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int len(char *s)
{
    int c = 0;
    while(*s)
    {
        c++;
        s++;
    }
    return c;
}

char *infin_add(char *s1, char *s2)
{
    int l1 = len(s1);
    int l2 = len(s2);
    if(l1 > l2)
    {
        swap(&s1, &s2);
        int temp = l1;
        l1 = l2;
        l2 = temp;
    }
    char *r = (char *)malloc(sizeof(char) * (l2 + 2));
    int sum = 0, carry = 0;
    r[l2 + 1] = '\0';
    for(int i = 1; i <= l1; i++)
    {
        sum = (s1[l1 - i] - '0') + (s2[l2 - i] - '0') + carry;
        r[l2 + 1 -i] = sum % 10 + '0';
        carry = sum / 10;
    }
    for(int i = 1; i <= l2 -l1; i++)
    {
        sum = (s2[l2 - l1 - i] - '0') + carry;
        r[l2 - l1 + 1 - i ] = sum % 10 + '0';
        carry = sum / 10;
    }
    if(carry)
    {
        r[0] = carry + '0';
    }
    else
    {
        r[0] = '\t';
    }
    return r;
}

char *infin_sub(char *s1, char *s2)
{
    int l1 = len(s1);
    int l2 = len(s2);
    if (l1 > l2)
    {
        swap(&s1, &s2);
        int temp = l1;
        l1 = l2;
        l2 = temp;
    }
    char *r = (char *)malloc(sizeof(char) * (l2 + 1));
    int sum = 0, carry = 0;
    r[l2] = '\0';
    for (int i = 1; i <= l1; i++)
    {
        sum = (s2[l2 - i] - '0') - (s1[l1 - i] - '0') - carry;
        if(sum < 0)
        {
            sum = sum + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        
        r[l2  - i] = sum % 10 + '0';
    }
    for (int i = 1; i <= l2 - l1; i++)
    {
        sum = (s2[l2 - l1 - i] - '0') - carry;
        if (sum < 0)
        {
            sum = sum + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        
        r[l2 - l1 - i] = sum % 10 + '0';
    }
    
    return r;
}

char *ft_strcpy(char *s)
{
    int i = 0;
    char *r = (char *)malloc(sizeof(char) * len(s));
    while(*s)
    {
        if(*s == '-')
        {
            s++;
        }
        else
        {
            r[i] = *s;
            i++;
            s++;
        }
    }
    r[i] = '\0';
    return r;
}

int main(int ac, char **av)
{
    char *s1 = av[1];
    char *s2 = av[2];
    int i = 0;
    char *res;
    if(ac == 3)
    {
        if ((s1[i] != '-' && s2[i] != '-') || (s1[i] == '-' && s2[i] == '-'))
        {
            if ((s1[i] == '-' && s2[i] == '-'))
            {
                s1 = ft_strcpy(s1);
                s2 = ft_strcpy(s2);
                write(1, "-", 1);
            }
            res = infin_add(s1, s2);
            while(res[i] == '\t' || res[i] == '0')
            {
                i++;
            }
            while (res[i])
            {
                write(1, &res[i], 1);
                i++;
            }
        }
        else
        {
            if((len(s1) > len(s2) && s1[0] == '-') || (len(s1) < len(s2) && s2[0] == '-'))
            {
                write(1, "-", 1);
            }
            s1 = ft_strcpy(s1);
            s2 = ft_strcpy(s2);
            res = infin_sub(s1, s2);
            while(res[i] == '\t' || res[i] == '0')
            {
                i++;
            }
            while (res[i])
            {
                write(1, &res[i], 1);
                i++;
            }
        }
        free(res);
    }
    write(1, "\n", 1);
    return 0;
}
