/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:02:55 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/03/18 16:08:36 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversor(int n, char *base, int len)
{
	int	count;

	count = 0;
	if (n < -(len - 1) || n > (len - 1))
		count += conversor((n / len), base, len);
	write(1, &base[(n % len) * ((n >= 0) - (n < 0))], 1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count += write(1, "-", 1);
	count += conversor(n, "0123456789", 10);
	return (count);
}
