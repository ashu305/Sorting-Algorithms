#include<iostream>

using namespace std;

void insertion_sort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int temp = arr[i + 1];



		int j = i;
		while ((arr[j] >= temp) && (j >= 0))
		{
			arr[j + 1] = arr[j];
			j--;
		}


		arr[j + 1] = temp;
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 5, 3, 2, 1, 6, 7, 4, 9};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "The original array is:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << "\nThe sorted array is:\n";
	insertion_sort(arr, size);

	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}