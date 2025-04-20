/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:44:34 by ael-khel          #+#    #+#             */
/*   Updated: 2025/04/20 17:45:37 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

#include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>

# define BUFFER_SIZE	8192u
# define TABLE_SIZE		16777619u

# define FNV_OFFSET 2166136261u
# define FNV_PRIME  16777619u
# define SECOND_PRIME 16777589u

typedef struct	s_entry
{
	char		*key;
	char		*value;
	uint32_t	value_len;
}	t_entry;

typedef	struct s_hash
{
	t_entry		**array;
	uint32_t	size;
	uint32_t	count;
}	t_hash;

uint32_t	ft_fnv1a( const char *key );
uint32_t	ft_djb2( const char *key );
uint32_t	ft_hash1( const char *key );
uint32_t	ft_hash2( const char *key );
uint32_t	ft_double_hashing( const char *key, uint32_t i );


void	ft_search_data( t_hash *table, const char *key );
bool	ft_init_table( t_hash *table );

int	ft_insert_data( t_hash *table, char *key, char *value, uint32_t value_len );

uint32_t	ft_getline( char **line );

int ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
uint32_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, uint32_t n);
char	*ft_strndup( const char *str, const int len );
void	ft_clean(t_hash *table);



#endif