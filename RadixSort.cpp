#include <bits/stdc++.h>
using namespace std;
#define k 10

int findmax(int *arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void countSort(int* arr, int m, int n);

void radixSort(int arr[], int n)
{
	int m = findmax(arr, n);

	for (int digit = 1; m / digit > 0; digit *= 10)
		countSort(arr, digit, n);

}

int main(int argc, char const *argv[])
{
	int arr[] = {170, 45, 75, 90, 8021, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "original array:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	radixSort(arr, n);

	cout << "Sorted array:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}


void countSort(int* arr, int m, int n)
{
	int count[k] = {0};

	for (int i = 0; i < n; i++)
	{
		count[ (arr[i] / m) % 10]++;
	}

	for (int i = 1; i < k; ++i)
	{
		count[i] += count[i - 1];
	}
	int result[n];

	for (int i = n - 1; i >= 0; --i)
	{
		result[count[ (arr[i] / m) % 10] - 1] = arr[i];
		count[ (arr[i] / m) % 10]--;
	}

	for (int i = 0; i < n; ++i)
	{
		arr[i] = result[i];
	}
}