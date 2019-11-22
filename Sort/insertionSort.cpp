#include <iostream>

using namespace std;


// Print output array
void printArr(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << " " << a[i];
	}
}

void insertionSort(int a[], int n)
{
	for(int i = 1; i < n; ++i)
	{
		int j = i - 1, key = a[i];
		while(j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;
	}
}

int main()
{
	int a[] = {41, 23, 74, 11, 65, 58, 94, 36, 99, 87};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "\nEntered array:";
	printArr(a, n);
	insertionSort(a, n);
	cout << "\nSorted array:";
	printArr(a, n);
	return 0;
}
