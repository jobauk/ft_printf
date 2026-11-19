/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strutils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/19 14:32:14 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUTILS_H
# define FT_STRUTILS_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>

size_t	ft_strlen(const char *s);

int		umaxtostr(char (*buf)[sizeof(uintmax_t) * CHAR_BIT],
			uintmax_t nb, const char *digits);

#endif
