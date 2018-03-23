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
	
	if(q < 1) goto loop;
	
	int array[q];
	puts("¬ведите числа: ");
	for(int i = 0; i < q; i++)		scanf("%i", array + i);
	
	int delta;
	puts("¬ведите кол-во перестановок: ");
	scanf("%i", &delta);
	
	if((delta >=  q) || (delta < 1))	goto loop;
	
	int direction;
	puts("¬ведите направление(1 - влево или 2 - вправо): ");
	scanf("%d", &direction);
	
	if((direction != 1) && (direction != 2))	goto loop;	
	
	puts("--------------------------\n");
	
	if(direction == 2)
	{
		for(int k = 0; k < delta; k++)	
		{
			for(int i = q; i > 0 ; i--)		*(array + i) = *(array + i - 1);
			
			*(array + k) = 0;
		
			for(int i = 0;i < q; i++)		printf("%d ", *(array + i));
			puts("\n");
		}
	}
	else
	{
		for(int k = 0; k < delta; k++)	
		{
			for(int i = 1;i < q; i++)		*(array + i - 1) = *(array + i);
			
			*(array + q - k - 1) = 0;
			
			for(int i = 0;i < q; i++)		printf("%d ", *(array + i));
			puts("\n");
		}	
	}

	return 0;
}
