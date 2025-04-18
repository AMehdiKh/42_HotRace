#include "hotrace.h"

/*
* todo: 
*	[x] Make Small Test data file
*	[ ] Make the int main following the subjects requirements: gnl + norm
    + can fetch the line from the giving data file (example.htr)
*	[ ] optimize int main
*	[ ] Generate Data For Testing (similar to an old rush)
*	[ ] find a good hash function
		+ chibihash64 (v2)
		+ chibihash64 (v1)
		+ rapidhash.protected
		+ Djb2
*	[ ] Test it against others
*	[ ] Norm
		+ is norminette should also be respected or just the Norm ?
*/

// to test:
// Djb2 hash function
// unsigned long hash(char *str) {

// unsigned long hash = 5381;
// int c;
// while ((c = *str++))
//     hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//     return hash % NUM_BUCKETS;

// }

//made this for learning hash tables
unsigned int    hash_function(const char *key)
{
    int hash_value = 0;
    
    int i = 0;
    while(key[i])
    {
        hash_value += key[i] * ft_strlen(key) * 56265;
        i++;
    }

    return (hash_value % 16777213);
}

void	ft_putstr_fd(char *s, int fd) // for writing the search queries
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

int	main(void)
{
	static char	*tab[16777213];
	char		*line = NULL;


	while ((line = get_next_line(1)) != NULL)
	{
		ft_putstr_fd("LINE: \n", 1);
		ft_putstr_fd(line, 1);



	}

	return (0);
}