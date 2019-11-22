#include <iostream>

using namespace std;


void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void selectionSort(int a[], int n)
{
	int min;
	for(int i = 0; i < n - 1; ++i)
	{
		min = i;
		for(int j = i + 1; j < n; ++j)
			if (a[j] < a[min])
				min = j;
		swap(&a[min], &a[i]);
	}
}

void printArr(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << " " << a[i];
	}
}

int main()
{
	int a[] = {41, 23, 74, 11, 65, 58, 94, 36, 99, 87};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "\nEntered array:";
	printArr(a, n);
	selectionSort(a, n);
	cout << "\nSorted array:";
	printArr(a, n);
	return 0;
}
