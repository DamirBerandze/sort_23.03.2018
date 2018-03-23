#include <stdio.h>
#include <Windows.h>

main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	loop:
	
	int q;
	puts("¬ведите кол-во чисел, которые вы хотите ввести: ");
	scanf("%i", &q);
	
	int array[q];
	puts("¬ведите числа: ");
	for(int i = 0; i < q; i++)		scanf("%i", array + i);
	
	int delta;
	puts("¬ведите кол-во перестановок: ");
	scanf("%i", &delta);
	
	if(delta >  q)	goto loop;
	
	int direction;
	puts("¬ведите направление(1 - влево или 2 - вправо): ");
	scanf("%d", &direction);
	
	if((direction != 1) && (direction != 2))	goto loop;
	
	int new_array[q];
	
	if(direction == 2)
	{
		for(int i = 0; i < q - delta; i++)		*(new_array + i + delta) = *(array + i);
		for(int i = 0; i < delta ;i++)		*(new_array + i) = 0;
	}
	else
	{
		for(int i = 0; i < q - delta; i++)				*(new_array + i) = *(array + i + delta);
		for(int i = q; i > q - delta - 1;i--)		*(new_array + i) = 0;
	}
	
	puts("--------------------------\n");
	for(int i = 0;i < q; i++)	printf("%d ", *(new_array + i));
	
	return 0;
}
