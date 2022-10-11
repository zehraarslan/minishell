
int check_null_cmd(char *str)
{
	int	i;

	i = 0;
    while (str[i] != '\0')
    {
        if (str[i] > 32 && str[i] < 127)
            return (0);
        i++;
    }
    return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*(s1 + 1) && *(s2 + 1) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strcmp2(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}