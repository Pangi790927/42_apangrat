#include <stdio.h>

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

int main()
{
	char str[] = "Urban Monkey";
	printf("%d\n", ft_strlen(str));	
}