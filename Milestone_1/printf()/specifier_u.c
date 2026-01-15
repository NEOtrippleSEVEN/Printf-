/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:39:26 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/15 16:42:22 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
// #include "libft.h"

int U_handler(int n)
{
    int     count;
    long    num;
    char    c;

    count = 0;
    num = n; 
    if (num < 0)
    {
        count += write(1, "4294967295", 11);
        // if(n == -2147483648)
        //     return(write(1, "2147483648", 11));
    }
    if (num > 9)
        count += U_handler (num / 10);
    c = (num % 10) + '0';
    count += write(1, &c, 1);
    return (count);
}