/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bigint.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/19 14:19:19 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/19 14:19:19 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGINT_H
# define FT_BIGINT_H

# include <stdint.h>

typedef struct s_bigint
{
	uint32_t	limbs[32];
}	t_bigint;

#endif
