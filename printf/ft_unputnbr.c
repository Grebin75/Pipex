/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:24:48 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/03/18 16:11:48 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversor(unsigned int n, char *base, unsigned int len)
{
	int	count;

	count = 0;
	if (n > (len - 1))
		count += conversor((n / len), base, len);
	write(1, &base[(n % len)], 1);
	return (count + 1);
}

int	ft_unputnbr(unsigned int n)
{
	int	count;

	count = 0;
	count += conversor(n, "0123456789", 10);
	return (count);
}
