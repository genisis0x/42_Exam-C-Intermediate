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
    int arr[l1 + 1][l2 + 1];

    int i_idx, j_idx, start, max_len = 0; // DP for LCS string
    for(int i = 0 ; i <= l1; i++)
        for(int j = 0; j <= l2; j++)
        {
            if(i == 0 || j ==0 ) // first col and first row set to 0 to get the reference 
            {
                arr[i][j] = 0;
            }
            else if(s1[i - 1] == s2[j -1])
            {
                arr[i][j] = 1 + arr[i -1][j -1]; // if char matches then add one to the previous diagonal element 
                if(max_len < arr[i][j]) // updated if the len of common string is maximum then the previous length
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
    
    for(int i = i_idx, j = j_idx; arr[i][j] > 0; i--, j--) // find the starting index form the string s1;
    {
        start = i - 1;
    }
    
    char *r = (char *)malloc(sizeof(char) * (max_len + 1));
    for (int i = start , j = 0; i < start + max_len; i++, j++)
    {
        r[j] = s1[i];
    }
    r[max_len] = '\0';
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
