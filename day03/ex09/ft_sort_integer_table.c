#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int aux; 

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] < tab[j])
				ft_swap(tab + i, tab + j);
			j++;
		}
		i++;
	}
}

int main()
{
	int table[] = {100, 100, 100, 100, 100, 100};
	int table_size = sizeof(table) / sizeof(int);

	ft_sort_integer_table(table, table_size);

	int i;
	for (i = 0; i < table_size; ++i)
	{
		printf("%d, \n", table[i]);
	}
}