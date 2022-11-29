/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:41:13 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/03/18 16:18:47 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_putchar(char h);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_point(unsigned long long n);
int	ft_unputnbr(unsigned int n);
int	ft_up(unsigned int n);
int	ft_low(unsigned int n);
int	ft_printf(const char *s, ...);

#endif
