#include <bits/stdc++.h>
using namespace std;



int max(int arr[], int child_index1, int child_index2)
{
	if (arr[child_index1] > arr[child_index2])
		return child_index1;

	return child_index2;
}



void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


void heapify(int arr[], int parent_index, int size)
{
	int child_index1 = 2 * parent_index + 1, child_index2 = 2 * parent_index + 2;


	if (child_index2 >= size && child_index1 >= size)
		return;

	if (child_index1 == size - 1)
	{
		if (arr[child_index1] > arr[parent_index])
			swap(&arr[child_index1], &arr[parent_index]);

		return;
	}

	int max_child_index = max(arr, child_index2, child_index1);


	if (arr[max_child_index] > arr[parent_index]) {
		swap(&arr[max_child_index], &arr[parent_index]);

		heapify(arr, max_child_index, size);
	}

}


void heapSort(int* arr, int size)
{
	int parent_index = (size - 2) / 2;

	for (int i = parent_index; i >= 0; --i)
	{
		heapify(arr, i, size);
	}


	for (int i = 0; i < size - 2; ++i)
	{
		swap(&arr[0], &arr[size - 1 - i]);

		heapify(arr, 0, size - i - 1);
	}

}

void printArray(int arr[], int size);


int main(int argc, char const *argv[])
{
	int size;
	cout << "Enter size of array: ";
	cin >> size;


	int arr[size];

	cout << "Enter values in array: " << endl;

	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}

	cout << "Original Array: ";
	printArray(arr, size);



	heapSort(arr, size);

	cout << "Sorted Array: ";
	printArray(arr, size);

	return 0;
}


void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}