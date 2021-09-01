#include <bits/stdc++.h>

using namespace std;

void merge(int* arr, int left, int mid, int right);

void mergesort(int* arr, int left, int right)
{

	if (left >= right)
		return;

	int mid = left + (right - left) / 2 ;
	mergesort(arr, left, mid);
	mergesort(arr, mid + 1, right);

	merge(arr, left, mid, right);
}

void print_array(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 5, 3, 2, 1, 6, 7, 4};
	int size = sizeof(arr) / sizeof(arr[0]);

	int left = 0, right = size - 1;
	cout << "Original array is:" << endl;
	print_array(arr, size);

	mergesort(arr, left, right);
	cout << "The sorted array is:" << endl;

	print_array(arr, size);


	return 0;
}



void merge(int* arr, int left, int mid, int right)
{
	int size1 = (mid - left) + 1;
	int size2 = (right - mid - 1) + 1;

	int left_arr[size1], right_arr[size2];

	for (int i = 0; i < size1; ++i)
	{
		left_arr[i] = arr[left + i];
	}

	for (int i = 0; i < size2; ++i)
	{
		right_arr[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, x = left;
	while (i < size1 && j < size2)
	{
		if (left_arr[i] <= right_arr[j])
		{
			arr[x] = left_arr[i];
			i++;
			x++;
		}

		else
		{
			arr[x] = right_arr[j];
			x++;
			j++;
		}
	}


	while (j < size2)
	{
		arr[x] = right_arr[j];
		x++;
		j++;
	}



	while (i < size1)
	{
		arr[x] = left_arr[i];
		x++;
		i++;
	}


}