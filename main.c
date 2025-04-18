
#include "hotrace.h"
#include <stdio.h> // ! For Debugging ; DONT FORGET TO REMOVE

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

//hash functionfrom old rush
// unsigned int	hash_function(const char *key)
// {
// 	unsigned int	hash = 5031;

// 	while (*key)
// 		hash = hash * 101 + *key++;

// 	return (hash % 16777213);
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

void	ft_putstr_fd(char *s, int fd) // for writing the search querys 
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

// Function to remove newline from string - We can simplify this by editing the gnl function so it doesnt return a newline or make a new function
char *trim_newline(char *str)
{
	char *end = str + ft_strlen(str) - 1;
	if (*end == '\n')
		*end = '\0';
	return (str);
}

int	main(void)
{
	static char	*tab[16777213];
	char *key = NULL;
	char *value = NULL;
	int reading_data = 1;

	while ((key = get_next_line(0)) != NULL) //retreave next line
	{
		// Check if we've reached the empty line that separates data from queries
		if (key[0] == '\n')
		{
			free(key);
			reading_data = 0;
			continue;
		}
        
		// Trim newlines
		key = trim_newline(key);

		if (reading_data == 1) // We're in etreaving mode
		{
			// printf("LINE: KEY  : %s\n", key);

			value = get_next_line(0); //fetch the next line as a value
			if (!value)
				break;

			// Trim newlines
        	key = trim_newline(key);

			// printf("LINE: VALUE: %s\n", value);

			// must delete the '\n' before storing 
			// store it
			tab[hash_function(trim_newline(key))] = trim_newline(value);
			
			// printf("HASH TABLE : %s\n", tab[hash_function(key)]);
		}

		else // We're in query mode
		{
			// printf("END OF RETRIEVING DATA - WERE IN QUERY MODE\n");
			value = tab[hash_function(key)];

			if (value)
				printf("%s\n", value);
			else
				printf("%s: Not found.\n", key);
			
			free(key);
		}
	}

	return (0);
}
