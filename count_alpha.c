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

#include <stdio.h>
#include <unistd.h>

int valid_char_small(char c)
{
	return (c >= 'a'  && c <= 'z');
}

int valid_char_Cap(char c)
{
	return (c >= 'A'  && c <= 'Z');
}

void ft_count_alpha(char *s)
{
	int char_arr[26] = {0};
	int flag = 1;
	int i = 0;
	while(s[i])
	{
		if(valid_char_small(s[i]))
		{
			char_arr[(int)(s[i] - 'a')] += 1;
		}
		if (valid_char_Cap(s[i]))
		{
			char_arr[(int)(s[i] - 'A')] += 1;
		}
		i++;
	}
	i = 0;
	while(s[i])
	{
		if (valid_char_Cap(s[i]) || valid_char_small(s[i]))
		{
			if(valid_char_Cap(s[i]) && char_arr[(int)(s[i] - 'A')] > 0)
			{
				if (flag == 1)
				{
					printf("%d%c", char_arr[(int)(s[i] - 'A')], s[i] + 32);
					char_arr[(int)(s[i] - 'A')] = 0;
					flag = 0;
				}
				else
				{
					printf(", %d%c", char_arr[(int)(s[i] - 'A')], s[i] + 32);
					char_arr[(int)(s[i] - 'A')] = 0;
				}
			}
			if(valid_char_small(s[i]) && char_arr[(int)(s[i] - 'a')] > 0)
			{
				if (flag == 1)
				{
					printf("%d%c", char_arr[(int)(s[i] - 'a')], s[i]);
					char_arr[(int)(s[i] - 'a')] = 0;
					flag = 0;
				}
				else
				{
					printf(", %d%c", char_arr[(int)(s[i] - 'a')], s[i]);
					char_arr[(int)(s[i] - 'a')] = 0;
				}

			}
		}
		i++;
	}
}
int main (int ac, char **av)
{
	if (ac == 2)
	{
		ft_count_alpha(av[1]);
	}
	printf("\n");
	return (0);
}
