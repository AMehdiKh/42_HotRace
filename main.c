
#include "hotrace.h"
#include <stdio.h> // ! For Debugging ; DONT FORGET TO REMOVE

void	forgive_me_lord_valgrind(char	*tab[]); //! Important But Might Not Be NESSECERY and DECIDE OUT LATER!

/*
* todo: 
*	[x] Make Small Test data file
*	[x] Make the int main following the subjects requirements: gnl + norm
*	[ ] optimize int main
*	[ ] Find a way to test the code efficiency 
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

int	ft_putstr_fd(char *s, int fd) // for writing the search querys 
{
	int		ret;
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	ret = write(fd, s, i);
	return (ret);
}

//hash functionfrom old rush
// unsigned int	hash_function(const char *key)
// {
// 	unsigned int	hash = 5031;

// 	while (*key)
// 		hash = hash * 101 + *key++;

// 	return (hash % 16777213);
// }


int	main(void)
{
	static char	*tab[16777213];
	char *key = NULL;
	char *value = NULL;
	int reading_data = 1;

	while ((key = get_next_line(0)) != NULL) //retreave next line
	{
		// Check if we've reached the empty line that separates data from queries
		if (!key[0])
		{
			free(key);
			reading_data = 0;
			continue;
		}

		if (reading_data == 1) // We're in etreaving mode
		{
			// printf("LINE: KEY  : :%s:\n", key); //DEBUG

			value = get_next_line(0); //fetch the next line as a value
			if (!value)
				break;

			// printf("LINE: VALUE: %s\n", value); //DEBUG

			// store it
			tab[hash_function(key)] = value;
			free(key);
			// printf("HASH TABLE : %s\n", tab[hash_function(key)]); //DEBUG
		}

		else // We're in query mode
		{
			// printf("END OF RETRIEVING DATA - WERE IN QUERY MODE\n"); //DEBUG
			value = tab[hash_function(key)];

			if (value)
				printf("%s\n", value);
			else
				printf("%s: Not found.\n", key);
			
			free(key);
		}
		
	}
	forgive_me_lord_valgrind(tab); //! Important But Might Not Be NESSECERY and DECIDE OUT LATER!

	return (0);
}

void	forgive_me_lord_valgrind(char	*tab[]) //! Important But Might Not Be NESSECERY and DECIDE OUT LATER!
{
	// if the code will be tested with valgrind
	// this is not a major leak but valgrind will label it as still reach able to get a clean valgrind report we can use this:
	// Free allocated memory in tab
	for (int i = 0; i < 16777213; ++i)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
	}
}