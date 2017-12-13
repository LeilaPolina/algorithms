#include "sort_algorithms.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//simple sorts
int* select_sort(int* arr, const int n)
{
	int i, j, min_ind;

	for (i = 0; i < n - 1; i++)
	{
		min_ind = i;
		for (j = i; j < n - 1; j++)
		{
			if (arr[min_ind] > arr[j + 1])
			{
				min_ind = j + 1;
			}
		}
		swap(&arr[min_ind], &arr[i]);
	}
	return arr;
}

int* bubble_sort(int* arr, const int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		int count = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				count++;
			}
		}
		if (count == 0)
			break;
	}
	return arr;
}

int* insert_sort(int* arr, const int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= 0, arr[j] > arr[j + 1]; j--)
		{
			swap(&arr[j], &arr[j + 1]);
		}
	}
	return arr;
}

//radix sort
int get_max(const int* arr, const int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void count_sort(int* arr, const int n, const int exp)
{
	int* output = (int*)malloc(sizeof(int)*n);
	assert(output);

	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];

	free(output);
}

int* radix_sort(int* arr, const int n)
{
	int m = get_max(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		count_sort(arr, n, exp);
	return arr;
}

//merge sort
void merging(int* arr, const int left, const int right)
{
	int half = left + (right - left) / 2;

	if (left >= right || half < left || half > right)
		return;

	if ((right == left + 1) && (arr[left] > arr[right]))
	{
		swap(&arr[left], &arr[right]);
		return;
	}

	// копируем данные в подмассив
	int* temp = (int*)malloc(sizeof(int) * (right - left + 1));
	assert(temp);
	for (int ind = 0; ind < (right - left + 1); ind++)
	{
		temp[ind] = arr[left + ind];
	}

	int j = 0;
	int k = half - left + 1;
	for (int i = left; i <= right; i++)
	{
		if (j > half - left)
		{
			arr[i] = temp[k];
			k++;
		}
		else if (k > right - left)
		{
			arr[i] = temp[j];
			j++;
		}
		else
		{
			if (temp[j] < temp[k])
			{
				arr[i] = temp[j];
				j++;
			}
			else
			{
				arr[i] = temp[k];
				k++;
			}
		}
	}
	free(temp);
}

void merge_sort(int* arr, const int left, const int right)
{
	if (left >= right) // когда достигаем длины подмассива 1
		return;
	int half = left + (right - left) / 2;
	merge_sort(arr, left, half);
	merge_sort(arr, half + 1, right);
	merging(arr, left, right);
}

//quick sort
int mediana(const int* arr, const int left, const int right) // returns index of median elements
{
	int middle = (left + right) / 2;
	if (arr[left] < arr[right])
	{
		if (arr[left] > arr[middle])
			return left;
		else if (arr[right] < arr[middle])
			return right;
		else
			return middle;
	}
	else
	{
		if (arr[left] < arr[middle])
			return left;
		else if (arr[right] > arr[middle])
			return right;
		else
			return middle;
	}
}

void quick_sort(int* arr, const int left_index, const int right_index)
{
	int pivot_ind = mediana(arr, left_index, right_index);
	int i = left_index;
	int j = right_index;
	int pivot = arr[pivot_ind];

	while (left_index < j || i < right_index)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
		else
		{
			if (left_index < j)
				quick_sort(arr, left_index, j);
			if (i < right_index)
				quick_sort(arr, i, right_index);
			return;
		}
	}
}