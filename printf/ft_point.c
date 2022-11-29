/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:13:02 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/03/18 16:12:08 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversor(unsigned long long n, char *base, unsigned long long len)
{
	int	count;

	count = 0;
	if (n > (len - 1))
		count += conversor((n / len), base, len);
	write(1, &base[(n % len)], 1);
	return (count + 1);
}

int	ft_point(unsigned long long n)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += conversor(n, "0123456789abcdef", 16);
	return (count);
}
