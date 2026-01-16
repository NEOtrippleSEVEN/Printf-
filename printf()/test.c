/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:55:01 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/16 18:34:54 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int main()
{
	int real = printf("output:  %u\n", 42);
	int mine = ft_printf("output:  %u\n", 42);
	printf("Real Return %d | My return %d\n", real, mine);
	int real1 = printf("output:  %u\n", 1255154);
	int mine1 = ft_printf("output:  %u\n", 1255154);
	printf("Real Return %d | My return %d\n", real1, mine1);
	int real3 = printf("output:  %u\n", -1);
	int mine3 = ft_printf("output:  %u\n", -1);
	printf("Real Return %d | My return %d\n", real3, mine3);
	int real4 = printf("output:  %u\n", 0);
	int mine4 = ft_printf("output:  %u\n", 0);
	printf("Real Return %d | My return %d\n", real4, mine4);
	int real5 = printf("output:  %u\n", 000125);
	int mine5 = ft_printf("output:  %u\n", 000125);
	printf("Real Return %d | My return %d\n", real5, mine5);
	int real6 = printf("output:  %u\n", 012);
	int mine6 = ft_printf("output:  %u\n", 012);
	printf("Real Return %d | My return %d\n", real6, mine6);
	int real7 = printf("output:  %u\n", -50);
	int mine7 = ft_printf("output:  %u\n", -50);
	printf("Real Return %d | My return %d\n", real7, mine7);
	int real8 = printf("output:  %u\n", 2147483647);
	int mine8 = ft_printf("output:  %u\n", 2147483647);
	printf("Real Return %d | My return %d\n", real8, mine8);
	int real9 = printf("output:  %u\n", 4000);
	int mine9 = ft_printf("output:  %u\n", 400000000000000);
	printf("Real Return %d | My return %d\n", real9, mine9);
	int real0 = printf("output:  %u\n", 500000);
	int mine0 = ft_printf("output:  %u\n", 500000);
	printf("Real Return %d | My return %d\n", real0, mine0);
	
	return 0;
}