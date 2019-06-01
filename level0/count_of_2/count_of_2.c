/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 01:37:39 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 01:12:53 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************* Passed Exam *******************************/

void checker(int n, int *count)
{
    if(n >= 10)
    {
        checker(n / 10, count);
        checker(n % 10, count);
    }
    if(n == 2)
        *count += 1;
}

int    count_of_2(int n)
{
    int i = 1;
    int count = 0;
    while(++i <= n)
    {
        checker(i, &count);
    }
    return count;
}

// #include <stdio.h>
// int main()
// {
//     int a;
//     printf("Please Enter the number: \n");
//     scanf("%d", &a);
//     printf("The count of 2 is: %d\n", count_of_2(a));
//     return 0;
// }
