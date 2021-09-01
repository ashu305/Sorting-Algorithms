#include <bits/stdc++.h>
using namespace std;
#define n 10
#define k 256

int main(void)
{
	char arr[n] = "ashutoshp";
	cout << "Original array:" << endl;

	//for(int i=0;i<n;i++)
	//{
	//	cout<<arr[i]<<" ";
	//}
	cout << arr << endl;

	int count[k] = {0};

	for (int i = 0; i < n - 1; i++)
	{
		count[arr[i]]++;
	}

	for (int i = 1; i < k; i++)
	{
		count[i] += count[i - 1];
	}

	char result[n];
	for (int i = n - 1; i >= 0; i--)
	{
		result[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}


	cout << "Sorted array:" << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = result[i];
	}

	cout << arr << endl;

	return 0;
}