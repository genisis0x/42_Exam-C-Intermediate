/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:12:36 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/30 13:03:34 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/********************************** ### Passed Exam Version ### *************************************/

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int c = 0, i = 0;
    while(s[i])
    {
        if(s[i] == '-')
        {
            i++;
        }
        else
        {
            c++;
            i++;
        }
    }
    return c;
}

char *ft_str_cpy(char *s)
{
    int i = 0, j = 0;
    char *res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    while(s[j])
    {
        if(s[j] == '-')
        {
            j++;
        }
        else
        {
            res[i] = s[j];
            j++;
            i++;
        }
    }
    res[i] = '\0';
    return res;
}

char *infin_mult(char *s1, char *s2)
{
    s1 = ft_str_cpy(s1);
    s2 = ft_str_cpy(s2);

    if(*s1 == '0' || *s2 == '0')
        return "0";
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int len = len1 + len2;
    
    int i, j;
    int *arr = (int *)malloc(sizeof(int) * len);
    for(i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
    for(i = len1 - 1; i >= 0; i--)
        for(j = len2 - 1; j >= 0; j--)
        {
            arr[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
        }
    for(i = len - 1; i > 0; i--)
    {
        arr[i - 1] += arr[i] / 10;
        arr[i] %= 10;
    }
    char *r = (char *)malloc(sizeof(char) * (len + 1));
    i = 0;
    j = 0;
    while (arr[i] == 0)
        i++;
    while(i < len)
    {
        r[j] = arr[i] + '0';
        i++;
        j++;
    }
    r[j] = '\0';
    return r;
}

int main (int ac, char **av)
{
     
    if(ac == 3)
    {
        char *s1 = av[1];
        char *s2 = av[2];
        if((*s1 == '-' && *s2 == '-') || (*s1 != '-' && *s2 != '-'))
        {
            char *r = infin_mult(s1, s2);
            while(*r)
            {
                write(1, r, 1);
                r++;
            }
        }
        else
        {
            s1 = ft_str_cpy(s1);
            s2 = ft_str_cpy(s2);
            if(*s1 != '0' && *s2 != '0')
                write(1, "-", 1);
            char *r = infin_mult(s1, s2);
            while(*r)
            {
                write(1, r, 1);
                r++;
            }
        }
    }
    write(1, "\n", 1);
}

// // Good TEST CASES

// // Input : 1
// num1 = 654154154151454545415415454 
// num2 = 63516561563156316545145146514654 
// Output : 
// 41549622603955309777243716069997997007620439937711509062916

// // Input : 2
// num1 = 1235421415454545454545454544
// num2 = 1714546546546545454544548544544545
// Output :
// 2118187521397235888154583183918321221520083884298838480662480
