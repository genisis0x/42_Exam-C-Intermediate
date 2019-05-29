/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 22:39:48 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/22 23:12:12 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define for(i, a, b) for(i = (a); i < (b); i++)

int find_pivot(int *arr, int n)
{
	int total_sum = 0;
	int remain_sum = 0;
	int i;
	for (i,0,n)
		total_sum += arr[i];
	for (i,0,n)
	{
		total_sum -= arr[i];
		if (remain_sum == total_sum)
			return (i);
		remain_sum += arr[i];
	}
	return(-1);
}

/**********
 TEST_MAIN
 *********/
#include <stdio.h>
int main (void)
{
	int arr[] = {1, 0, 1};
	printf("The pivot is: %d",find_pivot(arr, 3));
	return 0;
}
