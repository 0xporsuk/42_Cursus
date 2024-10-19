#include "libft.h"
static int	ft_wordcount(char const *s, char c)
{
	int count = 0;
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return count;
}
char	**ft_split(char const *s, char c)
{
	char **arr;
	int i;
	int j;
	int start;
	arr = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!arr && !s)
		return NULL;
	
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[j++] = ft_substr(s, start, i - start);
		}
	}
	arr[j] = NULL;
	return (arr);
}
int main()
{
    char *str = "Merhaba,dünya,nasılsın";
    char **words = ft_split(str, ',');
    
    int i = 0;
    while (words[i])
    {
        printf("%s\n", words[i]);
        free(words[i]);
        i++;
    }
    free(words);
    return (0);
}