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

void	ft_swap(char *a, char *b)
{
	int aux; 

	aux = *a;
	*a = *b;
	*b = aux;
}

char	*ft_strrev(char *str)
{
	int index; 
	int reverseLength;
	int lenght;

	if (str != NULL)
	{
		lenght = ft_strlen(str);
		reverseLength = lenght / 2;
		index = 0;
		while (index < reverseLength)
		{
			ft_swap(&str[index], &str[lenght - index - 1]);
			index++;
		}
		return str;
	}
	else
	{
		return NULL;
	}
}

int main()
{
	char str[] = "Urban Monkey";
	printf("%s\n", ft_strrev(str));	
}