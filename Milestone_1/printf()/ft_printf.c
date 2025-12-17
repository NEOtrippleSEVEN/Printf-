/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:30:48 by kingmurched       #+#    #+#             */
/*   Updated: 2025/12/17 17:14:40 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putnbr(int num)
{
	if(num < 0)
	{
		ft_putchar('-');
		ft_putnbr(-num);
	}
	if(num > 9)
	{
		ft_putchar( num / 10);
		ft_putnbr( num % 10);
	}


}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int i;
	int count;
	count = 0;
	i = 0;

	while(format[i] !='\0')
	{	
		// printf("%d\n", format[i]);
		if(format[i] == '%')
		{
			i++;
			if(format[i] == 'c')
			{
				char c = (char)va_arg(args, int);
				write(1, &c, 1);
				count++;
				i++;
			}
			else if(format[i] == 's')
			{
				char *str = va_arg(args, char *);
				if(!str[i])
					return NULL;
				int j = 0;
				while(str[j] != '\0')
				{
					write(1, &str[j], 1);
					count++;
					j++;
				}
				i++;
			}
			else if(format[i] == 'i')
			{
				// prints deciml (bse 10) number.
				// Convert an in t (42) into a sequence of char.
				
				/* 	
					1. Count the char to print 
					2. Conver int into pribntable char
							- typecasting wont work
							better use /10 = 4 and then 42 base 10 to get 2. 	
				*/
				}
			else if(format[i] == 'd')
			{
				// prints hexdeciml of  void pointer. 
			}
			else if(format[i] == 'p')
			{
				// Prints int in bse 10. 
			}
			else if(format[i] == 'u')
			{
				// Prints Unsigned deciml
			}
			
			else if(format[i] == 'x')
			{
				// Pritns  number in Hexdeciml
			}

		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
		
	}
	va_end(args);
	return(count);
	}
}

int main()
{
	int results = ft_printf("This is my age: %d\n", 25);
	printf("%d\n", results);
}



// 1 increment i to look at the specifier (c)
// 2. Check if the specifier is 'c'
// 3. Retrieve the argument using va_arg
// 4. Increment i to move past the specifier. 













