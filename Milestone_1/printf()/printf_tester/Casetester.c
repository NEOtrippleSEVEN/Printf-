/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casetester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuchins <jbuchins@student.42Wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:48:30 by jbuchins          #+#    #+#             */
/*   Updated: 2025/12/09 14:44:21 by jbuchins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

int x = 42;

int	ft_printf(const char *s, ...);

int	main(int argc, char **argv)
{
	if(argc != 3)
		return 0;
	int count_1;
	int count_2;
	setvbuf(stdout, NULL,_IONBF,0);

	if (strcmp(argv[1], "CHAR") == 0)
	{
		printf("og:");
		count_2 = printf("'%c'\n", argv[2][0]);
		printf("ft:");
		count_1 = ft_printf("'%c'\n", argv[2][0]);
		printf("%s ft=%d og=%d | INPUT:<%c>\n",argv[1], count_1, count_2, argv[2][0]);
	}
	else if (strcmp(argv[1], "STRING") == 0)
	{
		printf("og:");
		count_2 = printf("'%s'\n", argv[2]);
		printf("ft:");
		count_1 = ft_printf("'%s'\n", argv[2]);
		printf("%s ft=%d og=%d | INPUT:'%s'\n",argv[1], count_1, count_2, argv[2]);
	}
	else if (strcmp(argv[1], "POINTER") == 0)
	{
		char string[] = "Hello World";
		void * heap = malloc(sizeof(int));
		void * nil = NULL;
		static void * stat = &x; 
		void * Cases[] = {stat, nil, &string, &x, heap};
		printf("og:");
		count_2 = printf("'%p'\n", Cases[atoi(argv[2])]);
		printf("ft:");
		count_1 = ft_printf("'%p'\n", Cases[atoi(argv[2])]);
		printf("%s ft=%d og=%d | INPUT:'%s'\n",argv[1], count_1, count_2, argv[2]);
		free(heap);
	}
	else if(strcmp(argv[1], "DECIMAL") == 0)
	{
		int num = atoi(argv[2]);
		printf("og:");
		count_2 = printf("'%d'\n", num);
		printf("ft:");
		count_1 = ft_printf("'%d'\n", num);
		printf("%s ft=%d og=%d | INPUT:'%s'\n",argv[1], count_1, count_2, argv[2]);
	}
	else if(strcmp(argv[1], "UINT") == 0)
	{
		int num = atoi(argv[2]);
		printf("og:");
		count_2 = printf("'%u'\n", num);
		printf("ft:");
		count_1 = ft_printf("'%u'\n", num);
		printf("%s ft=%d og=%d | INPUT:'%s'\n",argv[1], count_1, count_2, argv[2]);
	}
	else if(strcmp(argv[1], "INT") == 0)
	{
		int num = atoi(argv[2]);
		printf("og:");
		count_2 = printf("'%i'\n", num);
		printf("ft:");
		count_1 = ft_printf("'%i'\n", num);
		printf("%s ft=%d og=%d | INPUT:'%s'\n",argv[1], count_1, count_2, argv[2]);
	}
	else if(strcmp(argv[1], "HEXLOW") == 0)
	{
		int num = atoi(argv[2]);
		printf("og:");
		count_2 = printf("'%x'\n", num);
		printf("ft:");
		count_1 = ft_printf("'%x'\n", num);
		printf("%s ft=%d og=%d | INPUT:'%s'\n",argv[1], count_1, count_2, argv[2]);
	}
	else if(strcmp(argv[1], "HEX") == 0)
	{
		int num = atoi(argv[2]);
		printf("og:");
		count_2 = printf("'%X'\n", num);
		printf("ft:");
		count_1 = ft_printf("'%X'\n", num);
		printf("%s ft=%d og=%d | INPUT:'%s'\n",argv[1], count_1, count_2, argv[2]);
	}
	return(0);
}
