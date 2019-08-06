/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:09:52 by exam              #+#    #+#             */
/*   Updated: 2019/04/02 09:28:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************* Passed Exam *******************************/

#include <stdio.h>
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

int	is_anagram(char *a, char *b)
{
    int temp = 0;
    if(len(a) == len(b))
    {
        for(int i = 0;a[i]; i++)
        {
            temp ^= a[i]; // xor operation
            temp ^= b[i]; // xor operation
        }
        if(!temp)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}


/***********
  TEST MAIN
***********/
#include <stdio.h>
int main(int ac, char *av[])
{
    if(ac > 0)
        (is_anagram(av[1], av[2])) ? printf("The two string are anagram") : printf("The two string are not anagram to each other");
    return 0;
}
