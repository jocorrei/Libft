#include "libft.h"

int count_words(char const *s, char c)
{
	int	i = 0;

	while(*s)
	{
		while(*s == c && *s)
			s++;
		while(*s != c && *s)
			s++;
		if(*s == c)
			i++;
	}
	return (i);

}

char **ft_split(char const *s, char c)
{
	char	**split;
	char	*start;
	int		i;
	int		len;

	i = 0;
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (*s)
	{
		while(*s == c && *s)
			s++;
		start = (char *)s;
		len = 0;
		while (*s++ != c && *s)
			len++;
		split[i++] = ft_substr(start, 0, len);
	}
	split[i + 1] = 0;
	return (split);
}
