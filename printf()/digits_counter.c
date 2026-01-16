/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:39:26 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/16 18:32:57 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int digit_counter(unsigned int n)
{
    int     count;
    unsigned long    num;
    char    c;

    count = 0;
    c = 0;
    num = n; 
    if(n == 0)
    {
        write(1, "0", 1);
        return 1;
    }
    if (num > 9)
        count += digit_counter (num / 10);
    c = (num % 10) + '0';
    count += write(1, &c, 1);
    return (count);
}
int main()
{
    int results = digit_counter(110);
    printf("\n");
    printf("Digit Count:  %d\n", results);
    return 0;
}