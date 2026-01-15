/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptnbr_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:07:10 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/14 18:34:44 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
// #include "libft.h"

// Helper function we discussed for integers
int ft_putnbr_printf(int n)
{
    int     count;
    long    num;
    char    c;

    count = 0;
    num = n; 
    if (num < 0)
    {
        count += write(1, "-", 1);
        if(n == -2147483648)
            return(write(1, "-2147483648", 11));
    }
    if (num > 9)
        count += ft_putnbr_printf(num / 10);
    c = (num % 10) + '0';
    count += write(1, &c, 1);
    return (count);
}
void print_number_recrusive(unsigned long n, int base, char *digits, int *count)
{
    if (n >= base)
        print_number_recrusive(n / base, base, digits, count);
    char c = digits[n % base];
    write(1, &c, 1);
    (*count)++;
}
// int main()
// {
//     int results = ft_putnbr_printf(123);
//     printf('%d\n', results);
//     return 0;
// }

/*
Recursion 

1. First call (n = 123)
    - num = 123 (long)
    - num > 9 -> Recursion call ft_putnbr_printf(12);
    stack frame created local vars count=0, num=123, c (not set yet)

2. Second Call (n = 12)
    - num = 12 
    - n > 9 -> Recrusive Call ft_putnbr_printf(1)
    New stack Frame pushed 

3. Third Call (n = 1)
    - num = 1
    - num <= 9 -> Recrusive Call ft_putnbr_printf(1)
    - c = '1'
    - count = 1 / prints 1

4. Back to second call 
    - Recieves return value 1 -> count += 1 (now 1)
    - c = (12 % 10) + '0' = '2';
    - Return 2

5. Back to first call 
    - Recieves 2 -> count += 2 (now 2)
    - return 3
*/