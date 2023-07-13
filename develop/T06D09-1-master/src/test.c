#include <stdio.h>

int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (buffer[i] % 2 == 0)
		{
			sum = sum + buffer[i];
		}
	}
	
	return sum;
}

int find_numbers(int* buffer, int length, int number, int* numbers, int *count)
{
	for (int *p = buffer; p - buffer < length; p++) {
		if (number % *p == 0) {
			*(numbers + *count) = *p;
			*count++;
		}
	}
}

int main() {
    int data[10];
    int datas[10];
    int n = 10, count = 0, num = 8;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    printf("\n\n");
	for (int i = 0; i < n; i++) {
		if (num % data[i] == 0) {
            printf("%d", data[i]);
			datas[count] = data[i];
			count++;
		}
	}
    printf("%d", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", datas[i]);
    }

    return 0;
}