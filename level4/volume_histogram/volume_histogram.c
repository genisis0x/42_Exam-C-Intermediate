/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:46:36 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/29 15:56:27 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    volume_histogram(int *histogram, int size)
{
	int left_max = 0;
	int right_max = 0;

	int low = 0;
	int high = size -1;
	int volume = 0;

	while( low <= high)
	{
		if(histogram[low] < histogram[high])
		{
			if(histogram[low] > left_max)
			{
				left_max = histogram[low];
			}
			else
				volume += left_max - histogram[low];
			low++;
		}
		else
		{
			if(histogram[high] > right_max)
			{
				right_max = histogram[high];
			}
			else
				volume += right_max - histogram[high];
			high--;
		}
	}
	return volume;
}

#include <stdio.h>
int main()
{
	int size;
	scanf("%d", &size);
	int arr[size];
	int i = 0;
	while (i < size)
	{
		scanf("%d", &arr[i++]);
	}
	printf("The volume of the given histogram is: %d\n", volume_histogram(arr, size));
	return 0;
}
