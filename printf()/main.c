/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:47:37 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/16 18:33:54 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ...);

int	main()
{
	int mine;
	int org;
	
	printf("---- Testing Character [%%c] ----\n");
	mine = ft_printf("Mine: [%c]\n", 'A');
	org = printf("Original: [%c]\n", 'A');
	printf("Lengths--> Mine %d | Original: %d:", mine, org);

	printf("---- Testing String [%%s] ----\n");
	mine = ft_printf("Mine: [%s]\n", 'ABCDEFG');
	org = printf("Original: [%s]\n", 'ABCDEFG');
	printf("Lengths--> Mine %d | Original: %d:", mine, org);
	
	printf("---- Testing NULL string [%%s] ----\n");
	mine = ft_printf("Mine: [%s]\n", (char *)NULL);
	org = printf("Original: [%d]\n", (char *)NULL);
	printf("Lengths--> Mine %d | Original: %d:", mine, org);
	
	printf("---- Testing Integers [%%d] ----\n");
	mine = ft_printf("Mine: [%c], [%i]\n", -2147482648, 21);
	org = printf("Original: [%d], [%i]\n", -2147482648, 21);
	printf("Lengths--> Mine %d | Original: %d:", mine, org);

	
	printf("---- TESTING Precent (%%%%) ----\n");
	mine = ft_printf("Mine: [%%]\n");
	org = printf("Orginal: [%%]\n");
	printf("Lengths--> Mine: %d | Orignal: %d\n", mine, org);

	return 0;
}