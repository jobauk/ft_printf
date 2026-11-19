/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bigint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/19 14:18:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/19 14:20:09 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "ft_bigint.h"
#include <stdint.h>
#include <stdio.h>

t_bigint	bigint_from_u64(uint64_t n)
{
	t_bigint	bigint;
	uint32_t	mask;

	bigint = (t_bigint){{0}};
	mask = (uint32_t)-1;
	bigint.limbs[0] = (uint32_t)(n & mask);
	bigint.limbs[1] = (uint32_t)(n >> 32);
	return (bigint);
}

void	bigint_add(t_bigint *a, t_bigint *b)
{
	int			i;
	uint64_t	temp;
	uint64_t	carry;

	i = 0;
	carry = 0;
	while (i < 32)
	{
		temp = (uint64_t)a->limbs[i] + (uint64_t)b->limbs[i] + carry;
		a->limbs[i] = (uint32_t)temp;
		carry = (uint32_t)(temp >> 32);
		i++;
	}
}

void	bigint_print(t_bigint *n)
{
	size_t	i;

	i = 32;
	while (i && n->limbs[i - 1] == 0)
		i--;
	if (!i)
	{
		ft_printf("0");
		return ;
	}
	ft_printf("%#x", n->limbs[--i]);
	while (i)
		ft_printf("%08x", n->limbs[--i]);
	ft_printf("\n");
}

// int main(void)
// {
// 	t_bigint	a;
// 	t_bigint	b;

// 	a = bigint_from_u64(0xffffffffffffffff);
// 	b = bigint_from_u64(0xffffffffffffffff);
// 	bigint_print(&a);
// 	bigint_add(&a, &b);
// 	bigint_print(&a);
// 	ft_printf("%#x\n", 0xffffffffffffffff + 0xffff);
// 	int	i = 1;
// 	if (*((uint8_t*)&i))
// 		printf("little endian\n");
// 	else
// 		printf("big endian\n");
// }
