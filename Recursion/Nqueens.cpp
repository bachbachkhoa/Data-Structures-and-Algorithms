#include <iostream>
#include <math.h>

using namespace std;

int a[20], k = 0;

bool Check(int x, int y)
{
    for(int i = 1; i < x; i++)
        if(a[i] == y || abs(i - x) == abs(a[i] - y) )
            return false;
    return true;
}
 
void Export(int n)
{
    k++;
    cout << "\n\n";
    cout << "Solution " << k << "\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j == a[i])
                cout << " Q";
            else
                cout << " -";
        }
        cout << "\n";
    }
}
 
void Try(int i, int n)
{
    for(int j = 1; j <= n; j++){
        if(Check(i, j)){
            a[i] = j;
            if(i == n)
                Export(n);
            else
                Try(i + 1, n);
        }
    }
}
 
int main()
{
    int n = 8;
    for(int i = 1; i <= n; i++)
    	a[i] = 0;
    Try(1, n);
    return 0;
}
