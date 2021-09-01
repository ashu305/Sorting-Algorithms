#include <iostream>

using namespace std;

int find_min(int *arr, int start, int end)
{
	int min = arr[start], index;
	while (start <= end)
	{
		if (arr[start] < min)
		{
			min = arr[start];
			index = start;
		}


		start++;
	}
	return index;
}

void swap(int* num1, int* num2)
{
	int temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}

void selection(int *arr, int size)
{
	int start = 0, end = size - 1;
	for (int i = 0; i < size - 1; ++i)
	{
		int min_index = find_min(arr, start, end);

		if (min_index == start)
			continue;

		swap(&arr[min_index], &arr[start]);
		start++;
	}


}

void print_array(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 5, 3, 2, 1, 6, 7, 4, 9};

	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "The original array is:\n";
	print_array(arr, size);

	selection(arr, size);
	print_array(arr, size);

	return 0;
}