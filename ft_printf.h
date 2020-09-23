/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:48:45 by ppipes            #+#    #+#             */
/*   Updated: 2020/07/22 19:23:49 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_options
{
	int		flag;
	int		width;
	int		precision;
	int		length;
	int		zero;
	char	type;
}				t_options;

int				ft_strlen(const char *s);
void			ft_putchar(char c, int n, t_options *opt);
void			ft_putstr(char *s, t_options *opt);
int				ft_printf(const char *format, ...);
int				ft_atoi(const char *nptr);
char			*ft_itoa(long long int num, int base);
char			*ft_strdup(const char *s);
void			ft_toupper(char *c);
int				ft_isdigit(int c);
void			type_char(va_list ap, t_options *opt);
void			type_string(va_list ap, t_options *opt);
int				type_unsigned_int(va_list ap, t_options *opt);
int				type_int(va_list ap, t_options *opt);
int				type_pointer(va_list ap, t_options *opt);
int				type_hex(va_list ap, t_options *opt);
void			type_percent(t_options *opt);
int				select_type(char format, va_list ap, t_options *opt);
void			parse_flag(const char **format, t_options *opt);
void			parse_width(const char **format, t_options *opt, va_list ap);
void			parse_prec(const char **format, t_options *opt, va_list ap);
void			erase_flags(t_options *opt);
int				count_spaces_str(int len, t_options *opt);
int				count_spaces_num(int len, t_options *opt);
void			print_minus(char **s, t_options *opt);
void			opt_flag_zero(char **s, t_options *opt);
void			opt_flag_minus_1(char *s, t_options *opt);

#endif
