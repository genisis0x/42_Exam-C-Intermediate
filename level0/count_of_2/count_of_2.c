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

void  ft_count_nbr(int nb, int *count)
{
	if (nb >=10)
	{
		ft_count_nbr( nb / 10, count);
		ft_count_nbr(nb % 10, count);
	}
	if (nb == 2)
		*count += 1;
}

int count_of_2(int n)
{
	int i = 1;
	int count = 0;

	while ( ++i <= n)
	{
		ft_count_nbr(i, &count);
	}
	return (count);
}

#include <stdlib.h>
#include <stdio.h>
int main (int ac , char **av)
{
	int res;
	res = count_of_2(atoi(av[1]));
	printf("%i", res);
}
