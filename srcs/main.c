/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:49:06 by ael-khel          #+#    #+#             */
/*   Updated: 2025/04/20 15:45:45 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdint.h>

uint32_t	ft_getline(char **line)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_size;
	static int	buffer_pos;
	char		*reserve;
	uint32_t	len;
	int			i;
	
	reserve = NULL;
	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_pos = 0;
			buffer_size = read(0, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
				return (free(reserve), 0);
		}
		i = 0;
		while ((buffer_pos + i) < buffer_size)
		{
			if (buffer[buffer_pos + (i++)] == '\n')
			{
				*line = ft_strjoin(reserve, ft_strndup(buffer + buffer_pos, i));
				buffer_pos += i;
				len = ft_strlen(reserve) + i;
				reserve = NULL;
				return ( len );
			}
		}
		reserve = ft_strndup(buffer + buffer_pos, i);
		buffer_pos += i;
	}
	return 0;
}

bool	ft_init_table( t_hash *table )
{
	uint32_t	i;

	table->array = malloc(sizeof(t_entry *) * TABLE_SIZE);
	if (!table->array)
		return (true);
	i = 0;
	while(i < TABLE_SIZE)
	{
		table->array[i] = NULL;
		++i;
	}
	table->size = TABLE_SIZE;
	table->count = 0;
	return (false);
}

int	ft_read_data( t_hash *table )
{
	char		*key;
	char		*value;
	bool		search_mode;
	
	search_mode = false;
	key = NULL;
	while (ft_getline(&key))
	{
		if (key[0] == '\n' && key[1] == '\0')
		{
			search_mode = true;
			continue;
		}
		if (!search_mode)
		{
			if (ft_insert_data(table, key, value, ft_getline(&value)))
				return (1);
		}
		else
			ft_search_data(table, key);
	}
	return (0);
}

int	ft_insert_data( t_hash *table, char *key, char *value, uint32_t value_len )
{
	uint32_t	index;
	uint32_t	i;
	
	i = 0;
	while (i < table->size)
	{
		index = ft_double_hashing(key, i);
		if (!table->array[index])
		{
			table->array[index] = malloc(sizeof(t_entry));
			if (!table->array[index])
				return ( 1 );
			table->array[index]->key = key;
			table->array[index]->value = value;
			table->array[index]->value_len = value_len;
			++table->count;
			break ;
		}
		else
		{
			if (ft_strcmp(table->array[index]->key, key) == 0)
			{
				free(table->array[index]->value);
				table->array[index]->value = value;
				break ;
			}
		}
		++i;
	}
	return ( 0 );
}

void	ft_search_data( t_hash *table, const char *key )
{
	uint32_t	index;
	uint32_t	i;
	
	i = 0;
	while (i < table->size)
	{
		index = ft_double_hashing(key, i);
		if (!table->array[index])
		{
			write(1, key, ft_strlen(key) - 1);
			write(1, ": Not found\n", 12);
			break ;
		}
		else
		{
			if (ft_strcmp(table->array[index]->key, key) == 0)
			{
				write(1, table->array[index]->value, table->array[index]->value_len);
				break ;
			}
		}
		++i;
	}
}


int	main( void )
{
	t_hash	table[1];

	if (ft_init_table(table))
		return (1);
	
	return (ft_read_data(table));
}