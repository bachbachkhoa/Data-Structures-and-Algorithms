#include <iostream>

using namespace std;

//binary search using recursion
int binarySearch(int a[], int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l + (r - l)/2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] > x)
			return binarySearch(a, l, mid - 1, x);
		else
		{
			return binarySearch(a, mid + 1, r, x);
		}
	}
	
	return -1;
}

//binary search not using recursion
int binarySearch1(int a[], int n, int x)
{
	int r = n - 1, l = 0;
	while(r >= l)
	{
		int mid = l + (r - l)/2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int main()
{
	int a[] = {-1, 0, 5, 12, 25, 30};
	int n = sizeof(a)/sizeof(a[0]);
	int x = 30;
	int result = binarySearch1(a, n, x);
	if (result == -1)
		cout << "Not found " << x;
	else
	{
		cout << x << " is at position " << result;
	}
	return 0;
}
