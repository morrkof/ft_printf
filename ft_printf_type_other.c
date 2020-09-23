/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_other.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:40:56 by ppipes            #+#    #+#             */
/*   Updated: 2020/07/22 18:50:36 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_char(va_list ap, t_options *opt)
{
	char c;

	c = va_arg(ap, int);
	if ((opt->flag == -1 || opt->flag == 0) && opt->width > 1)
		ft_putchar(' ', opt->width - 1, opt);
	ft_putchar(c, 1, opt);
	if (opt->flag == 1 && opt->width > 1)
		ft_putchar(' ', opt->width - 1, opt);
	erase_flags(opt);
}

void	type_string(va_list ap, t_options *opt)
{
	char *s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	if (opt->flag == -1)
		ft_putchar(' ', count_spaces_str(ft_strlen(s), opt), opt);
	if (opt->flag == 0 && opt->width > ft_strlen(s))
		ft_putchar('0', opt->width - ft_strlen(s), opt);
	ft_putstr(s, opt);
	if (opt->flag == 1)
		ft_putchar(' ', count_spaces_str(ft_strlen(s), opt), opt);
	erase_flags(opt);
}

int		type_pointer(va_list ap, t_options *opt)
{
	size_t	ptr;
	char	*s;

	if (!(ptr = va_arg(ap, size_t)))
		opt->zero = 1;
	if (!(s = ft_itoa(ptr, 16)))
		return (-1);
	if (opt->flag == 0 && opt->precision != -1)
		opt->flag = -1;
	if (opt->flag == -1 && opt->width > (ft_strlen(s) + 2))
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt) - 2, opt);
	ft_putstr("0x", opt);
	if (opt->precision != -1 && opt->precision > (ft_strlen(s)))
		ft_putchar('0', opt->precision - (ft_strlen(s)), opt);
	if (opt->flag == 0 && opt->width > (ft_strlen(s) + 2))
		ft_putchar('0', opt->width - (ft_strlen(s) + 2), opt);
	if (opt->precision || ptr)
		ft_putstr(s, opt);
	if (opt->flag == 1 && opt->width > (ft_strlen(s) + 2))
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt) - 2, opt);
	erase_flags(opt);
	free(s);
	return (0);
}

void	type_percent(t_options *opt)
{
	if (opt->flag == -1 && opt->width > 1)
		ft_putchar(' ', count_spaces_str(1, opt), opt);
	if (opt->flag == 0 && opt->width > 1)
		ft_putchar('0', opt->width - 1, opt);
	ft_putchar('%', 1, opt);
	if (opt->flag == 1 && opt->width > 1)
		ft_putchar(' ', count_spaces_str(1, opt), opt);
	erase_flags(opt);
}

int		count_spaces_str(int len, t_options *opt)
{
	int space;

	if (opt->precision == -1 || opt->precision > len)
		space = opt->width - len;
	else
		space = opt->width - opt->precision;
	if (space > 0)
		return (space);
	return (0);
}
