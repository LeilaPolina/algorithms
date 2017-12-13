#include "sort_algorithms.h"

int* fillrand_arr(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	return arr;
}

void show_arr(const int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void check_sorts()
{
	int* arr;
	int n = 19;
	arr = (int*)malloc(sizeof(int) * n);
	assert(arr);

	arr = fillrand_arr(arr, n);
	std::cout << "Your array:\n";
	show_arr(arr, n);

	std::cout << "\nYour array after sorting:\n";
	arr = radix_sort(arr, n);
	show_arr(arr, n);

	free(arr);
	getchar();
}

int main()
{
	check_sorts();
	return 0;
}