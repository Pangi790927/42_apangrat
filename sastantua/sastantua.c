char piramid_from_center(int x, int y, int size) 
{
	if (abs(x) + abs(y) < size)
		return '*'; 
	if (abs(x) + abs(y) == size && x != 0)
	{
		if (x < 0)
			return '/';
		else
			return '\\';
	}
	return '_';
}

int sastuantua_calculate_base_size(int size)
{
	int base_size = 3;
	int to_add = 2;
	int i = 2;

	// 3 .. 9 .. 15 
	// ***
	// *** *** ***
	// *** *** *** *** ***
	// *** *** *** *** *** *** *** ***
	// *** *** *** *** *** *** *** *** *** *** ***

	if (size == 1)
		return 3;

	while (i <= size)
	{
		base_size += 3 * to_add + (i % 2);
		to_add += i % 2;
		i++;
	}

	return base_size;
}

char sastuantua(int x, int y, int size)
{
	int i = 1;
	int total_height = (size + 2) * (size + 3) / 2 - 3;
	int current_height = 0;
	int piramid_base_size = sastuantua_calculate_base_size(size);

	while (i <= size) {
		current_height = (i + 2) * (i + 3) / 2 - 3;
		if (total_height + y <= current_height) {
			
			// printf("x: %d y: %d i: %d h: %d\n", x, y, i, current_height);
			// printf("%s\n", "alabalalalala ");

			return piramid_from_center(x // - (piramid_base_size - sastuantua_calculate_base_size(i))
									 , y + (total_height - current_height)
									 , sastuantua_calculate_base_size(i));
		}
		i++;
	}
	return '-';
}

char door(int x, int y, int size)
{
	if (size > 2 && x == size - 2 && y == -size + 1)
		return '$';

	if (x == 0 && y == 0)
		return '|';

	if (abs(x) < size && abs(y) < size * 2 - 1)
		return '|';

	return '0';
}

///////////////////////////////////////////////////////////////////////////////|

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[]) {
	if (argc < 2)
		return 0;

	int i;
	int j;
	int fig_size = sastuantua_calculate_base_size(atoi(argv[1]));
	int screen_size_x = fig_size * 2 + 1;
	int screen_size_y = (atoi(argv[1]) + 2) * (atoi(argv[1]) + 3) / 2 - 3;
	
	int center_x = fig_size;
	int center_y = screen_size_y - 1;
			
	for (i = 1; i < 6; ++i)
	{
		printf("base for %d: is %d\n", i, sastuantua_calculate_base_size(i));
	}

	for (i = 0; i < screen_size_y; ++i)
	{
		for (j = 0; j < screen_size_x; ++j)
		{
			if (door(j - center_x, i - center_y, (atoi(argv[1]) + 1) /2) == '0')
				printf("%c", sastuantua(j - center_x, i - center_y , atoi(argv[1])));
			else
				printf("%c", door(j - center_x, i - center_y, (atoi(argv[1]) + 1) /2));
		}
		printf("\n");
	}
}




