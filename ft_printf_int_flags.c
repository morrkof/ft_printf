/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:03:51 by ppipes            #+#    #+#             */
/*   Updated: 2020/07/21 00:06:06 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	opt_flag_zero(char **s, t_options *opt)
{
	if (opt->precision == -1)
		print_minus(s, opt);
	if (opt->precision != -1)
		opt->flag = -1;
	if (opt->flag == 0 && opt->width > ft_strlen(*s))
		ft_putchar('0', opt->width - ft_strlen(*s), opt);
}

void	opt_flag_minus_1(char *s, t_options *opt)
{
	if (opt->width > ft_strlen(s))
	{
		if (*s == '-' && opt->precision > ft_strlen(s))
			opt->width--;
		ft_putchar(' ', count_spaces_num(ft_strlen(s), opt), opt);
	}
}

void	print_minus(char **s, t_options *opt)
{
	if ((**s) == '-')
	{
		ft_putchar('-', 1, opt);
		(*s)++;
		opt->width--;
	}
}
