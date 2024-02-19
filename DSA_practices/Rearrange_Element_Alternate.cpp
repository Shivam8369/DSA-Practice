// Given an array having positive and negative numbers, our task is to arrange them in an alternate fashion such that every positive number is followed by a negative number and vice-versa maintaining the order of appearance. The number of positive and negative numbers need not to be equal. If there are more positive numbers then they have to appear at the end of the array , same condition for negative numbers also .

#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n, int st, int end)
{

	int temp = arr[end];
	for (int i = end; i>st; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[st] = temp;
}

void rearrange2(int arr[], int n)
{

	int i = 0, j = 0, k = 0;
	while (i < n && j < n && k < n)
	{

		if (k % 2 == 0)
		{

			if (arr[k] >= 0)
			{
				i = k, j = k;
				while (i < n && arr[i] >= 0)
					i++;
				if (i >= n)
					break;
				rotate(arr, n, j, i);
			}
		}

		else
		{

			if (arr[k] < 0)
			{
				i = k, j = k;
				while (j < n && arr[j] < 0)
					j++;

				if (j >= n)
					break;
				rotate(arr, n, i, j);
			}
		}
		k++;
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int size;
	cout<<"Enter the size of array ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the element: ";
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	// Function Call
	rearrange2(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}