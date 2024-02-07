#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char		*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strchr(char **tab, int c)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == (char)c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	int		s_len;
	char		*sub;

	sub = NULL;
	s_len = ft_strlen((char *)s) - start;
	if (start >= (unsigned int)ft_strlen((char *)s))
	{
		sub = malloc(sizeof(char));
		if (sub == NULL)
			return (sub);
		sub[0] = '\0';
		return (sub);
	}
	if (len <= s_len)
		sub = malloc(sizeof(char) * (len + 1));
	else if (len > s_len)
		sub = malloc(sizeof(char) * (s_len + 1));
	if (sub == NULL)
		return (sub);
	i = -1;
	while (s[start + ++i] && i < len)
		sub[i] = ((char *)s)[start + i];
	sub[i] = '\0';
	return (sub);
}

int	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (str == NULL)
		return (c);
	while (str[c] != '\0')
		c++;
	return (c);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	int			i;
	int			j;
	char		*sj;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	sj = malloc(sizeof(char) * (len1 + len2 + 1));
	if (sj == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sj[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sj[i + j] = s2[j];
		j++;
	}
	sj[i + j] = '\0';
	return (sj);
}

int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	ft_putstr_fd(int fd, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &(s[i]), 1);
		i++;
	}
}