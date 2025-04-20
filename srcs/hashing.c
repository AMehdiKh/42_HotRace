/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:56:07 by ael-khel          #+#    #+#             */
/*   Updated: 2025/04/20 15:42:58 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

uint32_t	ft_fnv1a( const char *key )
{
    uint32_t	hash;
	
	hash = FNV_OFFSET;
    while (*key)
	{
        hash ^= (uint8_t)(*key++);
        hash *= FNV_PRIME;
    }
    return ( hash );
}

uint32_t	ft_djb2( const char *key )
{
    uint32_t	hash;

	hash = 5381;
    while (*key)
	{
        hash = ((hash << 5) + hash) + (uint8_t)(*key++);
    }
    return ( hash );
}

uint32_t	ft_hash1( const char *key)
{
    return ( ft_fnv1a(key) % TABLE_SIZE );
}

uint32_t	ft_hash2(const char *key)
{
    return ( SECOND_PRIME - (ft_djb2(key) % SECOND_PRIME) );
}

uint32_t	ft_double_hashing(const char *key, uint32_t i)
{
    return ( (ft_hash1(key) + i * ft_hash2(key)) % TABLE_SIZE );
}