#include <stdio.h>
#include <Windows.h>

main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	loop:
	
	int q;
	puts("������� ���-�� �����, ������� �� ������ ������: ");
	scanf("%i", &q);
	
	int array[q];
	puts("������� �����: ");
	for(int i = 0; i < q; i++)		scanf("%i", array + i);
	
	int delta;
	puts("������� ���-�� ������������: ");
	scanf("%i", &delta);
	
	if(delta >  q)	goto loop;
	
	int direction;
	puts("������� �����������(1 - ����� ��� 2 - ������): ");
	scanf("%d", &direction);
	
	if((direction != 1) && (direction != 2))	goto loop;
	
	int array_delta[delta];
	
	if(direction == 2)
	{
		for(int i = 0; i < delta; i++)		*(array_delta + i) = *(array + q - delta + i);
		for(int i = q;i > 0; i--)			*(array + i) = *(array + i - delta);
		for(int i = 0; i < delta ;i++)		*(array + i) = *(array_delta + i);
	}
	else
	{
		for(int i = 0; i < delta ; i++)				*(array_delta + i) = *(array + i);
		for(int i = 0; i < q ;i++)					*(array + i) = *(array + i + delta);
		for(int i = q; i > q - delta - 1;i--)		*(array + i) = *(array_delta + q - i - 1);
	}
	
	puts("--------------------------\n");
	for(int i = 0;i < q; i++)	printf("%d ", *(array + i));
	
	return 0;
}
