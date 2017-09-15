#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int index;

	if (str != NULL)
	{
		index = 0;
		while (str[index] != '\0')
			index++;
		return index;
	}
	return -1;
	
}

int ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}

int ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int lenght;
	int result;
	int minus;
	
	if (str == NULL)
		return (0);
	i = 0;
	result = 0;
	minus = 1;
	lenght = ft_strlen(str);
	while (i < lenght && ft_is_space(str[i]))
		i++;
	if (i < lenght && str[i] == '-')
	{
		i++;
		minus = -1;
	}
	while (i < lenght && ft_is_digit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return result * minus;
}

int main()
{
	char str[] = "   -2147483648 ";
	int i = -2147483648;
	int b = i * -1;
	printf("%d\n", i);
	printf("%d\n", b);
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));	
}