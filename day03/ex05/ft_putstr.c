#include <stdio.h>

void ft_putchar(char c){
	printf("%c", c);
}

void	ft_putstr(char *str)
{
	int index;

	if (str != NULL)
	{
		index = 0;
		while (str[index] != '\0')
		{
			ft_putchar(str[index]);
			index++;
		}
	} 
}

int main()
{
	char str[] = "Urban Monkey";
	ft_putstr(str);	
}