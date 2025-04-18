
#ifndef HOTRACE_H
# define HOTRACE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h> // For read and write
# include <stdlib.h> // For Malloc
# include <limits.h> // for OPEN_MAX in gnl function

// Heleprs
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

// gnl
char	*read_to_static_buffer(int fd, char **static_buffer, char *buff);
char	*extract_line(char **static_buffer);
char	*clean_static_buffer(char **static_buffer);
char	*get_next_line(int fd);





#endif