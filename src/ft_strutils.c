/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strutils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/19 14:27:29 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s && *s++)
		n++;
	return (n);
}

int	umaxtostr(char (*buf)[sizeof(uintmax_t) * CHAR_BIT],
	uintmax_t nb, const char *digits)
{
	uintmax_t	base;
	char		*end;
	char		*ptr;

	base = ft_strlen(digits);
	end = *buf + sizeof(uintmax_t) * CHAR_BIT;
	ptr = end;
	while (nb)
	{
		*--ptr = digits[nb % base];
		nb /= base;
	}
	if (ptr == end)
		*--ptr = '0';
	return ((int)(end - ptr));
}
