/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:00:57 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 09:00:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************* Passed Exam *******************************/

#include <stdio.h>
void print_doublon(int *a, int na, int *b, int nb)
{
    int i = 0; int j = 0;
    int flag = 0;
    while (i < na && j < nb)
    {
        if(a[i] == b[j])
        {
            if(flag > 0 )
            {
                printf(" ");
            }
            printf("%d", a[i]);
            i++;
            j++;
            flag++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
    }
    printf("\n");
}

/*
int main (void)
{
    int a[] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
    int na = 11;
    int b[] = {100000};
    int nb = 1;
    print_doublon(a, na, b, nb);
    return 0;
}
*/
