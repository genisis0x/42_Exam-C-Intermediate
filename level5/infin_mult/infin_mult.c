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

int len(char *s)
{
    int c = 0;
    for(; *s; s++)
        c++;
    return c;
}

char *infin_mult(char *s1, char *s2)
{
    if(*s1 == '0' || *s2 == '0')
    {
        char *res =(char *)malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int l1 = len(s1);
    int l2 = len(s2);
    int len = l1 + l2;
    int *arr = (int *)malloc(sizeof(int) * (len));
    int i, j;
    for(i = 0; i < len; i++)
        arr[i] = 0;
    for(i = l1 -1; i >= 0; i--)
        for(j = l2 -1; j>= 0; j--)
        {
            arr[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
        }
    for(i = len - 1; i > 0; i--)
    {
        arr[i - 1] += arr[i] / 10;
        arr[i] %= 10;
    }
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    i = 0;
    j = 0;
    while(arr[i] == 0)
        i++;
    while(i < len)
    {
        res[j] = arr[i] + '0';
        j++;
        i++;
    }
    res[j] = '\0';
    return res;
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        char *s1 = av[1];
        char *s2 = av[2];
        if((*s1 == '-' && *s2 == '-') || (*s1 != '-' && *s2 != '-'))
        {
            if((*s1 == '-' && *s2 == '-'))
            {
                s1++;
                s2++;
            }
            char *res = infin_mult(s1, s2);
            while(*res)
            {
                write(1, res, 1);
                res++;
            }
        }
        else
        {
            if(*s1 == '-')
                s1++;
            if(*s2 == '-')
                s2++;
            if(*s1 != '0' && *s2 != '0')
                write(1, "-", 1);
            char *res = infin_mult(s1, s2);
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
