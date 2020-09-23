/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:00:26 by ppipes            #+#    #+#             */
/*   Updated: 2020/07/22 19:20:11 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	erase_flags(t_options *opt)
{
	opt->flag = -1;
	opt->width = 0;
	opt->precision = -1;
	opt->zero = 0;
	opt->type = '\0';
}

void	parse_flag(const char **format, t_options *opt)
{
	while (*(*format + 1) == '-' || *(*format + 1) == '0')
	{
		if (*(*format + 1) == '-')
			opt->flag = 1;
		if (*(*format + 1) == '0' && opt->flag != 1)
			opt->flag = 0;
		(*format)++;
	}
}

void	parse_width(const char **format, t_options *opt, va_list ap)
{
	if (ft_isdigit(*(*format + 1)))
	{
		opt->width = ft_atoi(*format + 1);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	else if (*(*format + 1) == '*')
	{
		opt->width = va_arg(ap, int);
		if (opt->width < 0)
		{
			opt->width = opt->width * -1;
			opt->flag = 1;
		}
		(*format)++;
	}
}

void	parse_prec(const char **format, t_options *opt, va_list ap)
{
	if (*(*format + 1) == '.')
	{
		opt->precision = 0;
		(*format)++;
		if (ft_isdigit(*(*format + 1)))
		{
			opt->precision = ft_atoi(*format + 1);
			while (ft_isdigit(*(*format + 1)))
				(*format)++;
		}
		else if (*(*format + 1) == '*')
		{
			opt->precision = va_arg(ap, int);
			(*format)++;
		}
	}
	if (opt->precision < 0)
		opt->precision = -1;
}

int		select_type(char format, va_list ap, t_options *opt)
{
	int error;

	error = 0;
	if (format == (opt->type = 'c'))
		type_char(ap, opt);
	else if (format == (opt->type = 's'))
		type_string(ap, opt);
	else if (format == (opt->type = 'u'))
		error = type_unsigned_int(ap, opt);
	else if (format == (opt->type = 'd'))
		error = type_int(ap, opt);
	else if (format == (opt->type = 'i'))
		error = type_int(ap, opt);
	else if (format == (opt->type = 'p'))
		error = type_pointer(ap, opt);
	else if (format == (opt->type = 'X'))
		error = type_hex(ap, opt);
	else if (format == (opt->type = 'x'))
		error = type_hex(ap, opt);
	else if (format == (opt->type = '%'))
		type_percent(opt);
	if (error)
		return (error);
	return (0);
}
