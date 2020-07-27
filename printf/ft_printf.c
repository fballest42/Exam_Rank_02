/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 08:55:23 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/24 09:33:41 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int			ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int			ft_numlen(long long n, int base_len)
{
	int i;

	i = 1;
	while (n >= base_len || n <=  -base_len)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}

void		ft_putnum(long long n, int base_len, char *base)
{
	if (n >= base_len)
		ft_putnum(n / base_len, base_len, base);
	write(1, &base[n %  base_len], 1);
}

int			ft_printf(char *format, ...)
{
	va_list		valist;
	char		*base, *s, *str;
	long		num;
	int			prec = 0,width = 0, ret = 0, len = 0, space = 0, zeros = 0, base_len, dot = 0, neg = 0;
	va_start(valist, format);
	str = (char *)format;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			prec =  0, width = 0, len = 0, space = 0, zeros = 0, dot = 0, neg = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				str++;
				dot = 1;
				while (*str >= '0' && *str <= '9')
				{
					prec = prec * 10 + (*str - 48);
					str++;
				}
			}
			if (*str == 's')
			{
				s = va_arg(valist, char *);
				if (!s)
					s = "(null)";
				len = ft_strlen(s);
			}
			if (*str == 'x')
			{
				num = va_arg(valist, unsigned);
				base = "0123456789abcdef";
				base_len = 16;
				len = ft_numlen(num, base_len);
			}
			if (*str == 'd')
			{
				num = va_arg(valist, int);
				base = "0123456789";
				base_len = 10;
				if (num < 0)
				{
					num = -num;
					neg = 1;
				}
				len = ft_numlen(num, base_len) + neg;
			}
			if (dot == 1 && prec > len && *str != 's')
				zeros = prec - len + neg;
			else if (dot == 1 && prec < len && *str == 's')
				len = prec;
			else if (dot == 1 && prec == 0 && (*str == 's' || num == 0))
				len = 0;
			space = width - len - zeros;
			while (space-- > 0)
			{
				write(1, " ", 1);
				ret++;
			}
			if (neg == 1)
				write(1, "-", 1);
			while (zeros-- > 0)
			{
				write(1, "0", 1);
				ret++;
			}
			if (*str == 's')
				write (1, s, len);
			else if (len > 0)
				ft_putnum(num, base_len, base);
			ret += len;
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			ret++;
		}
	}
	return (ret);
}
