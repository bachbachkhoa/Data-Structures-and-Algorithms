#include <iostream>

using namespace std;


void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}


// Print output array
void printArr(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << " " << a[i];
	}
}

void bubbleSort(int a[], int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = n - 1; j >= i + 1; --j)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}


int main()
{
	int a[] = {41, 23, 74, 11, 65, 58, 94, 36, 99, 87};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "\nEntered array:";
	printArr(a, n);
	bubbleSort(a, n);
	cout << "\nSorted array:";
	printArr(a, n);
	return 0;
	return 0;
}
