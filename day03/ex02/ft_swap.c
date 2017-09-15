#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int aux; 

	aux = *a;
	*a = *b;
	*b = aux;
}

int main()
{
	int a = -1;
	int b = 1;
	ft_swap(&a, &b);
	printf("%d%d\n", a, b);
}