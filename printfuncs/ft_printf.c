/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <stdint.h>
#include "../includes/ft_printf.h"
#include <stdio.h>

int			print_c(char c)
{
	ft_putchar(c);
	return (1);
}

int			print_str(char *c)
{
	ft_putstr(c);
	return (ft_strlen(c));
}

int			n_type(va_list *ap, int ret)
{
	int	*n;

	n = va_arg(*ap, int*);
	*n = ret;
	return (1);
}

int			ft_printf(char *fmt, ...)
{
	va_list 	ap;
	int			i;
	int			ret;
	t_params *at;

	va_start(ap, fmt);
	i = -1;
	ret = 0;
	if (!fmt)
		return (ret);
	while (fmt[++i])
		if (fmt[i] == '%')
		{
			i++;
			at = read_params(fmt, &i, &ap);
			if (fmt[i] == '%')
				ret += print_c('%');
			else if (fmt[i] == 's')
				ret += print_str(va_arg(ap, char *));
			else if (fmt[i] == 'd' || fmt[i] == 'i')
				ret += print_signed_num(&ap, at);
			else if (fmt[i] == 'D' || fmt[i] == 'u' || fmt[i] == 'U')
				ret += print_unsigned_num(&ap, at);
			else if (fmt[i] == 'c')
				ret += print_c((char)va_arg(ap, int));
			else if (fmt[i] == 'C')
				ret += print_c((unsigned char)va_arg(ap, int));
			else if (fmt[i] == 'o' || fmt[i] == 'O' || fmt[i] == 'x' || fmt[i] == 'X')
				ret += print_oct_hex(&ap, at, fmt[i]);
			else if (fmt[i] == 'n')
				ret += n_type(&ap, ret);
			del_params(&at);
		}
		else
			ret += print_c(fmt[i]);
	va_end(ap);
	return (ret);
}
