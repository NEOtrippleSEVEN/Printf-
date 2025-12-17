/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percenttest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuchins <jbuchins@student.42Wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:25:01 by jbuchins          #+#    #+#             */
/*   Updated: 2025/12/08 18:06:49 by jbuchins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libftprintf.h"

int main(int argc, char ** argv)
{
	setvbuf(stdout, NULL,_IONBF,0);
    int count_1;
    int count_2;
	printf("og:");
	count_2 = printf(argv[1]);
    printf("\nft:");
	count_1 = ft_printf(argv[1]);
	printf("\nPERCENT ft=%d og=%d INPUT:<%s>\n", count_1, count_2, argv[1]);
	return (0);
}