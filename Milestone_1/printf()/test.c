/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:55:01 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/15 15:17:23 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	printf("output:  %u\n", 42);
	printf("output:  %u\n", 1255154);
	printf("output:  %u\n", 4294967295);
	printf("output:  %u\n", -1);
	printf("output:  %u\n", 0);
	printf("output:  %u\n", 000125);
	printf("output:  %u\n", 012);
	printf("output:  %u\n", -50);
	printf("output:  %u\n", 2147483647);
	printf("output:  %u\n", 400000000000000);
	printf("output:  %u\n", 500000000000000);
	return 0;
}