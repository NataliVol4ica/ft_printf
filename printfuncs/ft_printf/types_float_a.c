/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

static void	type_aba(va_list *ap, t_params *p, char c, _Bool is_cap)
{
	(void)ap;
	(void)p;
	(void)c;
	(void)is_cap;
}

void		type_a(va_list *ap, t_params *p)
{
	type_aba(ap, p, 'x', 0);
}

void		type_ba(va_list *ap, t_params *p)
{
	type_aba(ap, p, 'X', 1);
}