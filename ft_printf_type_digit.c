/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:38:25 by ppipes            #+#    #+#             */
/*   Updated: 2020/07/22 19:23:56 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_int(va_list ap, t_options *opt)
{
	int		num;
	char	*s;
	char	*tmp;

	if (!(num = va_arg(ap, int)))
		opt->zero = 1;
	if (!(tmp = ft_itoa(num, 10)))
		return (-1);
	s = tmp;
	if (opt->flag == 0)
		opt_flag_zero(&s, opt);
	if (opt->flag == -1)
		opt_flag_minus_1(s, opt);
	if (opt->precision != -1 && opt->precision > ft_strlen(s))
	{
		print_minus(&s, opt);
		ft_putchar('0', opt->precision - ft_strlen(s), opt);
	}
	if (opt->precision || num)
		ft_putstr(s, opt);
	if (opt->flag == 1 && opt->width > ft_strlen(s))
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt), opt);
	erase_flags(opt);
	free(tmp);
	return (0);
}

int	type_unsigned_int(va_list ap, t_options *opt)
{
	unsigned int	u;
	char			*s;

	if (!(u = va_arg(ap, unsigned int)))
		opt->zero = 1;
	if (!(s = ft_itoa(u, 10)))
		return (-1);
	if (opt->flag == 0 && opt->precision != -1)
		opt->flag = -1;
	if (opt->flag == -1 && opt->width > ft_strlen(s))
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt), opt);
	if (opt->flag == 0 && opt->width > ft_strlen(s))
		ft_putchar('0', opt->width - ft_strlen(s), opt);
	if (opt->precision != -1 && opt->precision > ft_strlen(s))
		ft_putchar('0', opt->precision - ft_strlen(s), opt);
	if (opt->precision || u)
		ft_putstr(s, opt);
	if (opt->flag == 1 && opt->width > ft_strlen(s))
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt), opt);
	erase_flags(opt);
	free(s);
	return (0);
}

int	type_hex(va_list ap, t_options *opt)
{
	unsigned int	hex;
	char			*s;

	if (!(hex = va_arg(ap, unsigned int)))
		opt->zero = 1;
	if (!(s = ft_itoa(hex, 16)))
		return (-1);
	if (opt->type == 'X')
		ft_toupper(s);
	if (opt->flag == 0 && opt->precision != -1)
		opt->flag = -1;
	if (opt->flag == -1 && opt->width > ft_strlen(s))
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt), opt);
	if (opt->flag == 0 && opt->width > ft_strlen(s))
		ft_putchar('0', opt->width - ft_strlen(s), opt);
	if (opt->precision != -1 && opt->precision > ft_strlen(s))
		ft_putchar('0', opt->precision - ft_strlen(s), opt);
	if (opt->precision || hex)
		ft_putstr(s, opt);
	if (opt->flag == 1 && opt->width > ft_strlen(s))
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt), opt);
	erase_flags(opt);
	free(s);
	return (0);
}

int	count_spaces_num(int len, t_options *opt)
{
	int space;

	if (opt->precision > len || (opt->precision == 0 && opt->zero == 1))
	{
		space = opt->width - opt->precision;
		return (space);
	}
	space = opt->width - len;
	return (space);
}
