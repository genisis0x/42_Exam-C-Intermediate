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
int is_cap_alpha(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int is_sma_alpha(char c)
{
    return (c >= 'a' && c <= 'z');
}

void count_alp(char *s)
{
    int arr[26] = {0};
    int i = 0, flag = 0;
    while(s[i])
    {
        if(is_cap_alpha(s[i]))
            arr[(int)s[i] - 'A'] += 1;
        else if(is_sma_alpha(s[i]))
            arr[(int)s[i] - 'a'] += 1;
        i++;
    }
    i = 0;
    while(s[i])
    {
        if(is_cap_alpha(s[i]) || is_sma_alpha(s[i]))
        {
            if(is_cap_alpha(s[i]) && arr[(int)s[i] - 'A'] > 0)
            {
                if(flag == 0)
                {
                    printf("%d%c", arr[(int)s[i] - 'A'], s[i] + 32);
                    flag++;
                    arr[(int)s[i] - 'A'] = 0;
                }
                else
                {
                    printf(", %d%c", arr[(int)s[i] - 'A'], s[i] + 32);
                    arr[(int)s[i] - 'A'] = 0;
                }
            }
            else if(is_sma_alpha(s[i]) && arr[(int)s[i] - 'a'] > 0)
            {
                if(flag == 0)
                {
                    printf("%d%c", arr[(int)s[i] - 'a'], s[i]);
                    flag++;
                    arr[(int)s[i] - 'a'] = 0;
                }
                else
                {
                    printf(", %d%c", arr[(int)s[i] - 'a'], s[i]);
                    arr[(int)s[i] - 'a'] = 0;
                }
            }
            
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        count_alp(av[1]);
    }
    printf("\n");
}
