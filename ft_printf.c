/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 01:52:20 by ppipes            #+#    #+#             */
/*   Updated: 2020/07/20 21:56:59 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int n, t_options *opt)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
		opt->length++;
	}
}

void	ft_putstr(char *s, t_options *opt)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		if (opt->type == 's' && opt->precision <= i && opt->precision != -1)
			break ;
		ft_putchar(s[i], 1, opt);
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	opt;
	int			error;

	va_start(ap, format);
	opt.length = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			erase_flags(&opt);
			parse_flag(&format, &opt);
			parse_width(&format, &opt, ap);
			parse_prec(&format, &opt, ap);
			if ((error = select_type(*(format + 1), ap, &opt)))
				return (error);
			format++;
		}
		else
			ft_putchar(*format, 1, &opt);
		if (*format != '\0')
			format++;
	}
	va_end(ap);
	return (opt.length);
}
