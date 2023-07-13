/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input (int *buffer, int *length, int *flag);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers, int *count);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main()
{
	int flag = 0;
	int data[NMAX], len;
	int new_data[NMAX];
	int count = 0;
	input(data, &len, &flag);
	if (flag != 1) {
		int sum = sum_numbers(data, len);
		printf("%d", sum);
		find_numbers(data, len, sum, new_data, &count);
		output(new_data, count);
	}
	else printf("n/a");

	return 0;
}

void input(int *buffer, int *length, int *flag) {
	char end;
	int d;
	scanf("%d%c", length, &end);
	if (end == '\n') {
		for (int *p = buffer; p - buffer < *length; p++) {
			d = scanf("%d", p);
			if (d != 1) *flag = 1;
		}
	}
	else *flag = 1;
}

void output(int *buffer, int length) {
	for (int *p = buffer; p - buffer < length; p++) {
		printf("%d ", *p);
	}
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	
	for (int i = 1; i < length; i++)
	{
		if (buffer[i] % 2 == 0)
		{
			sum = sum + buffer[i];
		}
	}
	
	return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers, int *count)
{
	for (int *p = buffer; p - buffer < length; p++) {
		if (number % *p == 0) {
			*(numbers + *count) = *p;
			*count++;
		}
	}

	return *numbers;
}
