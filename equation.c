/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 21:57:55 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 01:13:19 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    equation(int n)
{
	int i,j,k;

	for (i = 0;i < 10; i++)
		for(j = 0; j < 10; j++)
			for (k = 0; k < 10; k++)
				if ((i * 10 + j) + (k * 10 + i) == n)
					printf("A = %d, B = %d, C = %d\n", i,j,k);
}

/**********
 TEST MAIN
 *********/
#include <stdlib.h>
int main (int ac, char **av)
{
	if (ac == 2)
	{
		equation(atoi(av[1]));
	}
	return (0);
}
