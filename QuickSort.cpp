#include <bits/stdc++.h>
using namespace std;


void print_array(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int* num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}
int partition(int *arr, int start, int end)
{
	int piviot = arr[end];

	int j = start - 1;
	for (int i = start; i < end; ++i)
	{
		if (arr[i] < piviot)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}

	}

	swap(&arr[j + 1], &arr[end]);
	return j + 1;
}

void quickSort(int *arr, int start, int end)
{
	if (start >= end)
		return;

	int pivot_index = partition(arr, start, end);

	quickSort(arr, start, pivot_index - 1);
	quickSort(arr, pivot_index + 1, end);

}
int main(int argc, char const *argv[])
{
	int arr[] = {6, 1, 7, 9, 3, 8, 2, 5, 4, 0};
	int size = sizeof(arr) / sizeof(arr[0]);

	int start = 0, end = size - 1;
	cout << "Original array is:" << endl;
	print_array(arr, size);

	quickSort(arr, start, end);
	cout << "The sorted array is:" << endl;

	print_array(arr, size);


	return 0;
}