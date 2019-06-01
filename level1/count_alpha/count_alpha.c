/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 00:58:44 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/01 01:37:16 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************ #### Passed Final Exam #### *************************************/

#include <stdio.h>
#include <unistd.h>
#define is_cap(c) (c >= 'A' && c <= 'Z')
#define is_small(c) (c >= 'a' && c <= 'z')

void count_alpha(char *s)
{
    int arr[26] = {0};
    int flag = 0;
    for(int i = 0; s[i]; i++)
    {
        if(is_cap(s[i]))
            arr[(int)(s[i] - 'A')] += 1;
        else if(is_small(s[i]))
            arr[(int)(s[i] - 'a')] += 1;
    }
    while(*s)
    {
        if(is_cap(*s) || is_small(*s))
        {
            if(is_cap(*s) && arr[(int)(*s - 'A')] > 0)
            {
                if(flag == 0)
                {
                    printf("%d%c",arr[(int)(*s - 'A')], *s + 32);
                    arr[(int)(*s - 'A')] = 0;
                    flag++;
                }
                else
                {
                    printf(", %d%c",arr[(int)(*s - 'A')], *s + 32);
                    arr[(int)(*s - 'A')] = 0;
                }
            }
            else if(is_small(*s) && arr[(int)(*s - 'a')] > 0)
            {
                if(flag == 0)
                {
                    printf("%d%c",arr[(int)(*s - 'a')], *s);
                    arr[(int)(*s - 'a')] = 0;
                    flag++;
                }
                else
                {
                    printf(", %d%c",arr[(int)(*s - 'a')], *s);
                    arr[(int)(*s - 'a')] = 0;
                }
            }
        }
        s++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        count_alpha(av[1]);
    }
    printf("\n");
    return 0;
}

/**************************************** GOOD TEST CASES *************************************/

// TEST CASE 1: 

/*
Input:
"PxRTKJgL eULs0WBjrh 9kgAuSvNwnDidbtR Cq2jZcbuBzT7Ikm aBQ BXRcF p4ygbwLlcYrTQJCk0 BLZ4lFM312PhCA 9N0WVvYtKLHlhy h7c2IZ"
Output:
3p, 2x, 5r, 5t, 5k, 4j, 3g, 8l, 1e, 3u, 2s, 4w, 8b, 5h, 3a, 3v, 3n, 2d, 3i, 7c, 3q, 4z, 2m, 2f, 4y$
*/

// TEST CASE 2: 

/*
Input:
"aQ7WIrj5DUJC01E 2H5VATk b5tBq609uosnFUwG ebf35Z4YEuaRXcdn rx2IeT9YtomFN3Gi Ifdm1OalPhruK Q0s NB4YSXU9OTPAxhuy Pu3lXBC JTYrLQ GqFu52afDI QpqtC sZVcQ8 PDZzQ dae26xV"
Output:
7a, 9q, 2w, 5i, 5r, 3j, 6d, 9u, 5c, 5e, 3h, 3v, 7t, 2k, 5b, 4o, 4s, 4n, 6f, 3g, 4z, 5y, 6x, 2m, 3l, 5p$
*/

// TEST CASE 3:

/*
Input:
"hAJ2oO0qiPvDkH eQd3yCr1S7U2G UpZfCwG8IlgQ4eL k96 6s7Xei5kRZpG gqNGr1oF8at 8w40X2EyozTKC qshYdv 2531Mz 0ZKfpAoQ DNp1cuR9qBoYn jrY PLwn64mcZU YUP5QweZoIkGSBN JDO3se"
Output:
3h, 3a, 3j, 8o, 8q, 4i, 7p, 2v, 5d, 6k, 6e, 6y, 5c, 5r, 5s, 5u, 7g, 7z, 3f, 4w, 3l, 2x, 5n, 2t, 2m, 2b$
*/

// TEST CASE 4:

/*
Input:
"9lINPUTpbVChkYQH0 U23HuPgO9mwdaEvrz MCWtfuHLAzoJQkn7c fK70RYO Vyo DVWGUqw TpQqS6A2t4eu9sb NW8ABubhSmEztD yan8cv5 eXA6zK2 uMdjg7V 7DeP9 sJiD08RHpLwSXd GSFl04Q zR5v6cGMwa slAdTvrj9K7nfB"
Output:
5l, 2i, 5n, 6p, 8u, 6t, 5b, 8v, 5c, 6h, 5k, 4y, 6q, 5g, 4o, 5m, 7w, 8d, 8a, 5e, 5r, 5z, 4f, 4j, 7s, 2x$
*/

// TEST CASE 5:

/*
Input:
"IvmOrDNyF gtY3MyefW6hP4 8vDT 7DM5cR2aXSink4b PnZ0EMVW3iGNQ prEfmHxvFTCXt KWhC ZOXQqRKuHtMPb IbXh1lLnjK MpK6R83mBwjEs eiXKuQjP ATSsEPBY7xm4vby5 m9NnSZEjl05 XyzFoSD 9Ck dYkO xQCSMpdmc db2vKXNEy"
Output:
5i, 6v, 12m, 4o, 5r, 7d, 8n, 8y, 5f, 2g, 6t, 8e, 4w, 5h, 8p, 6c, 2a, 10x, 7s, 9k, 7b, 4z, 5q, 2u, 3l, 4j$
*/

// TEST CASE 6:

/*
Input:
"fkQDdz6RyMmqUIb cn2WoRr LJmoc qAegk lPWKt kte07q DNI 2cYJmqIQzKBg 2bRlmBM zbeIJq fI3rlO6U897Rwaesc rfTONv AfO9JpUIFzGv CT5 r7OV dM4sh9U GmOaA71FBhJYzlbCr R5MHZ1OP8wlfx3Co"
Output:
7f, 5k, 7q, 4d, 6z, 10r, 3y, 9m, 4u, 6i, 7b, 7c, 3n, 4w, 9o, 6l, 5j, 5a, 4e, 4g, 3p, 4t, 2s, 3v, 3h, 1x$
*/
