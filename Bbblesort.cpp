#include <bits/stdc++.h>
using namespace std;

void swap(int* num1, int* num2)
{
	int temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}

int main(void)
{
	int arr[] = {5, 3, 2, 4, 2, 6, 1, 0, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "original array:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i; ++j)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
	cout << "Sorted array:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}