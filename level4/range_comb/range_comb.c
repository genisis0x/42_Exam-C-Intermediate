/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmeetsingh <manmeetsingh@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 02:19:35 by manmeetsing       #+#    #+#             */
/*   Updated: 2019/05/12 02:41:53 by manmeetsing      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int fac(int n)
{
    int fact = 1;
    for(int i = n; i >= 1; i--)
        fact *= n;
    return fact;
}

int    **range_comb(int n)
{
    int **res = (int **)malloc(sizeof(int *) * fac(n));
    
    for(int i = 0 ; i < fac(n); i++)
        res[i] = (int *)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
        res[0][i] = i;
    
    for(int i = 1; i < fac(n); i++)
        res[i] = generate(res[i - 1], 0, n -1);
    
    return res;
}