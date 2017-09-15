#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0){
		*div = a / b;
		*mod = a % b;
	}
}

int main()
{
	int a = 9, b = 4;
	int div, mod;

	ft_div_mod(a, b, &div, &mod);

	printf("%d %d\n", div, mod);
}