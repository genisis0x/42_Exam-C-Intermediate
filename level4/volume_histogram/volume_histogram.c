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

/********************* ###### Fully Tested and Passed in Exam ##### ***********************/

int    volume_histogram(int *histogram, int size)
{
	int left_max = 0;
	int right_max = 0;

	int low = 0;
	int high = size -1;
	int volume = 0;

	while( low <= high) // Termination Condition 
	{
		if(histogram[low] < histogram[high]) // Traverse from left if the building arch is bigger of right side
		{
			if(histogram[low] > left_max) // if the Left global max is lesser upgrade the max and procced.
				left_max = histogram[low];
			else
				volume += left_max - histogram[low]; // Calculate Volume if the left_max is not modified.
			low++;
		}
		else // Traverse from right if the building arch is bigger of left side
		{
			if(histogram[high] > right_max) // if the Right global max is lesser upgrade the max and procced.
				right_max = histogram[high];
			else
				volume += right_max - histogram[high]; // Calculate Volume if the right_max is not modified.
			high--;
		}
	}
	return volume;
}

// #include <stdio.h>
// int main()
// {
// 	int size;
// 	scanf("%d", &size);
// 	int arr[size];
// 	int i = 0;
// 	while (i < size)
// 	{
// 		scanf("%d", &arr[i++]);
// 	}
// 	printf("The volume of the given histogram is: %d\n", volume_histogram(arr, size));
// 	return 0;
// }

