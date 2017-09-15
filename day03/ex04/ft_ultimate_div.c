#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div_res;
	int mod_res;

	if (*b != 0){
		div_res = *a / *b;
		mod_res = *a % *b;

		*a = div_res;
		*b = mod_res;
	}
}

int main()
{
	int a = 9, b = 4;
	ft_ultimate_div_mod(&a, &b);

	printf("%d %d\n", a, b);
}