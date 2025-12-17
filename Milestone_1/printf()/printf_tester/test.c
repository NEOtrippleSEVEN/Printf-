/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuchins <jbuchins@student.42Wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:08:21 by jbuchins          #+#    #+#             */
/*   Updated: 2025/12/08 15:33:35 by jbuchins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include "../libftprintf.h"

int	main(int argc, char **argv)
{
	int			count_1;
	int			count_2;

	if (argc == 1)
		return (0);
	if (!strcmp(argv[1], "CHAR") && argc == 3)
	{
		count_1 = ft_printf("ft_CHAR: '%c'\n", argv[2][0]);
		count_2 = printf("og_CHAR: '%c'\n", argv[2][0]);
		printf("CHAR ft=%d og=%d\n", count_1, count_2);
		return (0);
	}
	else if (!strcmp(argv[1], "STRING") && argc == 3)
	{
		count_1 = ft_printf("ft_STRING: '%s'\n", argv[2]);
		count_2 = printf("og_STRING: '%s'\n", argv[2]);
		printf("STRING ft=%d og=%d\n", count_1, count_2);
		return (0);
	}
	else if (!strcmp(argv[1], "POINTER") && argc == 3)
	{
		static void	*ptr;
		char		a;
		int			x;
		char		*chrptr;
		int			*intptr;
		void		*vdptr;
		int			*heapptr;
		void		**dblvdptr;
		char		str[] = "Hello World!";
		ptr = argv[1];
		a = 'a';
		x = 42;
		chrptr = &a;
		intptr = &x;
		vdptr = argv[1];
		dblvdptr = &vdptr;
		if (!strcmp(argv[2], "0"))
		{
			count_1 = ft_printf("ft_POINTER: '%p'\n", ptr);
			count_2 = printf("og_POINTER: '%p'\n", ptr);
			printf("POINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "1"))
		{
			count_1 = ft_printf("ft_NULLPOINTER: '%p'\n", NULL);
			count_2 = printf("og_NULLPOINTER: '%p'\n", NULL);
			printf("NULLPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "2"))
		{
			count_1 = ft_printf("ft_STATICPOINTER: '%p'\n", ptr);
			count_2 = printf("og_STATICPOINTER: '%p'\n", ptr);
			printf("STATICPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "3"))
		{
			count_1 = ft_printf("ft_CHARPOINTER: '%p'\n", chrptr);
			count_2 = printf("og_CHARPOINTER: '%p'\n", chrptr);
			printf("CHARPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "4"))
		{
			count_1 = ft_printf("ft_INTPOINTER: '%p'\n", intptr);
			count_2 = printf("og_INTPOINTER: '%p'\n", intptr);
			printf("INTPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "5"))
		{
			count_1 = ft_printf("ft_VOIDPOINTER: '%p'\n", vdptr);
			count_2 = printf("og_VOIDPOINTER: '%p'\n", vdptr);
			printf("VOIDPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "6"))
		{
			heapptr = malloc(sizeof(int));
			count_1 = ft_printf("ft_HEAPPOINTER: '%p'\n", heapptr);
			count_2 = printf("og_HEAPPOINTER: '%p'\n", heapptr);
			printf("HEAPPOINTER ft=%d og=%d\n", count_1, count_2);
			free(heapptr);
		}
		else if (!strcmp(argv[2], "7"))
		{
			count_1 = ft_printf("ft_DOUBLEPOINTER: '%p'\n", dblvdptr);
			count_2 = printf("og_DOUBLEPOINTER: '%p'\n", dblvdptr);
			printf("DOUBLEPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "8"))
		{
			count_1 = ft_printf("ft_MULTIPOINTER: '%p %p %p'\n", vdptr, vdptr,
					vdptr);
			count_2 = printf("og_MULTIPOINTER: '%p %p %p'\n", vdptr, vdptr,
					vdptr);
			printf("MULTIPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		else if (!strcmp(argv[2], "9"))
		{
			count_1 = ft_printf("ft_STRINGPOINTER: '%p %p'\n", str, str + 4);
			count_2 = printf("og_STRINGPOINTER: '%p %p'\n", str, str + 4);
			printf("STRINGPOINTER ft=%d og=%d\n", count_1, count_2);
		}
		return (0); 
	}
	else if(!strcmp(argv[1], "DECIMAL"))
	{
		count_1 = ft_printf("ft_DECIMAL: '%d'\n", atoi(argv[2]));
		count_2 = printf("og_DECIMAL: '%d'\n", atoi(argv[2]));
		printf("DECIMAL ft=%d og=%d\n", count_1, count_2);
	}
	else if(!strcmp(argv[1], "UINT"))
	{
		count_1 = ft_printf("ft_UINT: '%u'\n", atoi(argv[2]));
		count_2 = printf("og_UINT: '%u'\n", atoi(argv[2]));
		printf("UINT ft=%d og=%d\n", count_1, count_2);
	}
	else if(!strcmp(argv[1], "INT"))
	{
		count_1 = ft_printf("ft_INT: '%i'\n", atoi(argv[2]));
		count_2 = printf("og_INT: '%i'\n", atoi(argv[2]));
		printf("INT ft=%d og=%d\n", count_1, count_2);
	}
	else if(!strcmp(argv[1], "HEXLOW"))
	{
		count_1 = ft_printf("ft_HEXLOW: '%x'\n", atoi(argv[2]));
		count_2 = printf("og_HEXLOW: '%x'\n", atoi(argv[2]));
		printf("HEXLOW ft=%d og=%d\n", count_1, count_2);
	}
	else if(!strcmp(argv[1], "HEX"))
	{
		count_1 = ft_printf("ft_HEX: '%X'\n", atoi(argv[2]));
		count_2 = printf("og_HEX: '%X'\n", atoi(argv[2]));
		printf("HEX ft=%d og=%d\n", count_1, count_2);
	}
	return(0);
}
