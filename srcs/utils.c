/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 06:22:20 by ael-khel          #+#    #+#             */
/*   Updated: 2025/04/20 15:46:09 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strndup( const char *str, const int len )
{
	char	*dup;

	dup = malloc(len + 1);
	if (!dup)
		return ( NULL );
	ft_memcpy(dup, str, len);
	dup[len] = '\0';
	return ( dup );
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	uint32_t	len1;
	uint32_t	len2;

	if (!s1)
		return ((char *)s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return ( NULL );
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	free(s1);
	free(s2);
	str[len1 + len2] = '\0';
	return (str);
}

uint32_t	ft_strlen(const char *s)
{
	uint32_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, uint32_t n)
{
	uint32_t	i;

	if (!dst && !src)
		return ( NULL );
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		++i;
	}
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
	{
        ++s1;
        ++s2;
    }
    return ((int)(*s1) - (int)(*s2));
}