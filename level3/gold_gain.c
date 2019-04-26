/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 02:26:50 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/26 03:08:40 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define max(a, b) (a > b ? a : b)
int gold_gain(int **mine, int n)
{
	int row = n, col = n;
	int r, c;
	for (c = col -1; c >= 0; c--)
	{	
		for (r = row -1; r >= 0; r--)
		{
			int right = (c == col -1) ? 0 : mine[r][c + 1];
			int right_up = (c == col -1 || r == 0) ? 0 : mine[r - 1][c + 1];
			int right_down = (c == col -1 || r == row -1) ?  0  : mine[r + 1][c + 1];

			mine[r][c] += max(right, max(right_down, right_up));
		}
	}
	int max_gold = mine[0][0];
	for (r = 1; r < row; r++)
	{
		max_gold = max(max_gold, mine[r][0]);
	}
	return max_gold;
}
/**************
	TEST MAIN
**************/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int side;
	scanf("%d", &side);
	int **mine = (int **)malloc(sizeof(int *) * side);
	for(int r = 0; r < side; r++)
	{
		mine[r] = (int *)malloc(sizeof(int) * side);
		for(int c = 0; c < side; c++)
		{
			scanf("%d", &(mine[r][c]));
		}
	}
	printf("The max gold gain is: %d\n", gold_gain(mine, side));
	return 0;
}
