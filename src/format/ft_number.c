/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_number.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:17:31 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_format.h"
#include "../ft_spec.h"
#include "../ft_strutils.h"
#include "../ft_utils.h"

static void	fmt_number(t_output *o, const t_spec *s, t_nbfmt n)
{
	const char	*sign;
	int			len;
	int			zeros;
	int			padding;

	sign = 0x0;
	len = umaxtostr(&o->buf, n.nb, n.digits) * !(s->prec == 0 && n.nb == 0);
	zeros = max_int(0, s->prec - len);
	if (n.neg)
		sign = "-";
	else if (s->flags & F_SIGN)
		sign = "+";
	else if (s->flags & F_BLANK)
		sign = " ";
	padding = max_int(0, s->width - (!!sign + zeros + len));
	if (!(s->flags & F_LEFT) && (s->flags & F_ZERO) && s->prec == -1)
		zeros += padding;
	else if (!(s->flags & F_LEFT))
		o->tokens[o->n++] = token_repeat(' ', padding);
	if (sign)
		o->tokens[o->n++] = token_span(sign, 1);
	o->tokens[o->n++] = token_repeat('0', zeros);
	o->tokens[o->n++] = token_span((o->buf + UINTMAX_BITS - len), len);
	if (s->flags & F_LEFT)
		o->tokens[o->n++] = token_repeat(' ', padding);
}

void	fmt_ptr(t_output *o, const t_spec *spec, va_list *ap)
{
	void	*ptr;

	ptr = va_arg(*ap, void *);
	if (!ptr)
		fmt_txt_padded(o, spec, "(nil)", 5);
	else
		fmt_number(o, spec, (t_nbfmt){(uintptr_t)ptr, "0123456789abcdef", 0});
}

void	fmt_int(t_output *o, const t_spec *spec, va_list *ap)
{
	int		nb;

	nb = va_arg(*ap, int);
	if (nb < 0)
		fmt_number(o, spec,
			(t_nbfmt){(uintmax_t)(-(unsigned)nb), "0123456789", 1});
	else
		fmt_number(o, spec, (t_nbfmt){(uintmax_t)nb, "0123456789", 0});
}

void	fmt_uint(t_output *o, const t_spec *spec, va_list *ap)
{
	fmt_number(o, spec, (t_nbfmt){va_arg(*ap, unsigned int), "0123456789", 0});
}

void	fmt_hex(t_output *o, const t_spec *spec, va_list *ap)
{
	unsigned int	nb;

	nb = va_arg(*ap, unsigned int);
	if (spec->conv == 'x')
		fmt_number(o, spec, (t_nbfmt){nb, "0123456789abcdef", 0});
	else if (spec->conv == 'X')
		fmt_number(o, spec, (t_nbfmt){nb, "0123456789ABCDEF", 0});
}
