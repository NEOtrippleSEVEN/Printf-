/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:06:50 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/15 16:14:03 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

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
            if (format[i] == '\0');
            if (format[i] == 'c')
                {
                int c = va_arg(args, int);  // Reads 8 bytes from current position --> gets 25 
                count += write(1, &c, 1);   // advances args by 8-bytes (Alignes)
                char c = va_arg(args, int); // pulls 8 byte slot, truncates into char. 
                count += write(1, &c, 1);
                }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                // We left off here: you need to handle the NULL case ??
                if (!str)
                    count += write(1, "(null)", 6);
                else
                    while (*str)
                        count += write(1, str++, 1);
            }
            else if (format[i] == 'd' || format[i] == 'i')
                count += ft_putnbr_print(va_arg(args, int));
            else if (format[i] == '%')
                count += write(1, "%", 1);
            else if (format[i] == 'u')
            {
                unsigned int val = va_arg(args, unsigned int);
                if(val == 0)
                {
                    val % 10 + '0';
                    write(1, &val, 1);
                    val / 10;
                    
                    val ++;
                }
            }
        }
        else
            count += write(1, &format[i], 1);
    }
    va_end(args);
    return (count);
}
