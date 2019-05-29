/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 04:02:57 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/10 09:28:19 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************** #### PASSED FINAL EXAM #### *************************************/

#include <unistd.h>
#include <stdlib.h>

void put_str(char *s)
{
    while(*s)
    {
        write(1, s, 1);
        s++;
    }
}

int len(char *s)
{
    int c = 0;
    for(; *s; s++)
        c++;
    return c;
}

char *str_max_len(char *s1, char *s2)
{
    int len1 = len(s1);
    int len2 = len(s2);
    int arr[len1 + 1][len2 + 1];
    int i, j;
    int len_max = 0;
    int start, i_idx, j_idx;

    for(i = 0; i <= len1; i++)
        for(j = 0; j <= len2; j++)
        {
            if(i == 0 || j == 0) // first col and first row set to 0 to get the reference
                arr[i][j] = 0;
            else if(s1[i -1] == s2[j -1])
            {
                arr[i][j] = 1 + arr[i -1][j -1]; // if char matches then add one to the previous diagonal element 
                if(arr[i][j] > len_max) // updated if the len of common string is maximum then the previous length
                {
                    len_max = arr[i][j];
                    i_idx = i;
                    j_idx = j;
                }
            }
            else
                arr[i][j] = 0;
        }
    if(len_max == 0)
    {
        char *r = (char *)malloc(sizeof(char) * 1);
        r[0] = '\0';
        return r;
    }
    
    for(i = i_idx, j = j_idx; arr[i][j] > 0; i--, j--) // find the starting index form the string s1;
        start = i - 1;
    
    char *r = (char *)malloc(sizeof(char) * (len_max + 1)); 
    for(i = start, j = 0; i < start + len_max; i++, j++) // store the valid string and return it.
    {
        r[j] = s1[i];
    }
    r[len_max] = '\0';
    return r;
}

int main(int ac, char **av)
{
    if(ac >= 2)
    {
        char *res = av[1];
        if(ac == 2)
        {
            put_str(res);
        }
        else
        {
            int i = 1;
            while(++i < ac)
            {
                res = str_max_len(res, av[i]);
                if(len(res) == 0)
                    break;
            }
            put_str(res);
        }
    }
    write(1, "\n", 1);
    return 0;
}


/**************************************** GOOD TEST CASES *************************************/

// TEST CASE 1: 

/*
Input:
"Bonjour"

Output:
Bonjour$
*/

// TEST CASE 2: 

/*
Input:
"bonjouran" "bonjouran" "confiseriean" "bonne annee"

Output:
on$
*/

// TEST CASE 3:

/*
Input:
"bonjour an" "bonjour an" "confiserie an" "bonne annee"

Output:
 an$
*/

// TEST CASE 4:

/*
Input:
"voila" "voila" "ouais ben voila"

Output:
voila$
*/

// TEST CASE 5:

/*
Input:
"bosdsdfnjodur" "atehhellosd" "afkuonjosurafg" "headfgllosf" "fghellosag

Output:
os$
*/
