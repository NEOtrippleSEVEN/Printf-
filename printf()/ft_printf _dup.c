/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf _dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:06:50 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/16 19:12:45 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int handle_num(const char *format, ...)
{  
    va_list args_num;
    int i;
    int count;
    
    va_start(args_num, format);
    i =  0;
    count = 0;
    if (format[i] == 'd' || format[i] == 'i')
        count += ft_putnbr_printf(va_arg(args_num, int));
       
    else if (format[i] == 'u')
        count += digits_counter(va_arg(args_num, unsigned int));
    // %d, %i. %u, %x, %X, %p 
}
char handle_text(const char *format, ...)
{
    va_list args_text;
    int i;
    int count;
    
    va_start(args_text, format);
    i =  0;
    count = 0;
    if (format[i] == 'c')
        {
        char c = va_arg(args_text, int); // pulls 8 byte slot, truncates into char. 
        count += write(1, &c, 1);
        } 
    else if (format[i] == '%')
        count += write(1, "%", 1);
    else if (format[i] == 's')
    {
        char *str = va_arg(args_text, char *);
        // We left off here: you need to handle the NULL case ??
        if (!str)
            count += write(1, "(null)", 6);
        else
            while (*str)
                count += write(1, str++, 1);
    }
}  

int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     count;

    va_start(args, format);
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++; // Move to specifier
            if (format[i] == '\0')
                return count;
          
            // else if(format[i] == 'x' || format[i] == 'X')
            
            // else if(format[i] == 'p')
        }
        else
            count += write(1, &format[i], 1);
    }
    va_end(args);
    return (count);
}
