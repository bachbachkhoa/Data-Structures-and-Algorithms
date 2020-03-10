#include <iostream>

using namespace std;

void swap(int *a, *b)
{
	int t = *a;
	*a = *b;
	*b = *a;
}

void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[largest, a[i]]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	for(int i = n/2 - 1; i >= 0; --i)
		heappfy(a, n, i);
}

int main()
{
	return 0;
}
