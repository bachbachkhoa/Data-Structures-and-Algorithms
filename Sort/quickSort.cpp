#include <iostream>

using namespace std;


// Swap 2 elements
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

/*This function takes middle element as pivot, swap 
pivot and last element, places the pivot element at 
its correct position in sorted array, and places all
smaller element(smaller than pivot) to left of pivot, 
places all greater element to right of pivot*/
int partition(int a[], int left, int right)
{
	int pivotIndex = (left + right)/2;
	swap(&a[pivotIndex], &a[right]);
	int i = left, j = right - 1;
	while(true)
	{
		while(i <= j && a[i] < a[right]) i++;
		while(j >= i && a[j] > a[right]) j--;
		if (j <= i) break;
		swap(&a[i], &a[j]);
		i++;
		j--;
	}
	swap(&a[i], &a[right]);
	return i;
}

// This fuction implements quick sort
// a[]: array to be sorted
// left: starting index
// right: ending index
void quickSort(int a[], int left, int right)
{
	if (left < right)
	{
		// pi is the position of pivot before
		int pi = partition(a, left, right);

		//quick sort two sub array
		quickSort(a, left, pi - 1);
		quickSort(a, pi + 1, right);
	}
}

int main()
{
	int a[] = {41, 23, 74, 11, 65, 58, 94, 36, 99, 87};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "\nEntered array:";
	printArr(a, n);
	quickSort(a, 0, n - 1);
	cout << "\nSorted array:";
	printArr(a, n);
	return 0;
}
