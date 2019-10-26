#include <iostream>

using namespace std;

// Number of men and women
#define n 4

// This function return true if women w prefers men m1 over men m
bool wPrefersM1OverM(int prefer[2*n][n], int w, int m1, int m)
{
    for (int i; i < n; ++i)
    {
        if (prefer[w][i] == m1)
            return true;
        if (prefer[w][i] == m)
            return false;
    }
}

void stableMarrige(int prefer[2*n][n])
{
    // Stores partner of women. The value of wPartner[i]
    // indicates the partner assigned to women (n + i).
    // The women numbers between n and (2*n - 1).
    // The value -1 indicates that women (n + i) is free.
    int wPartner[n];

    // An array to store availability of men. If mFree[i] is
    // true, then man 'i' is free, otherwise engaged.
    bool mFree[n];

    // Initialize all men and women as free
    for (int i = 0; i < n; ++i)
        wPartner[i] = -1;
    for (int i = 0; i < n; ++i)
        mFree[i] = true;

    int freeCount = n;

    while(freeCount > 0)
    {
        int m;
        for (m = 0; m < n; ++m)
            if (mFree[m] == true)
                break;

        for (int i = 0; i < n && mFree[m] == true; ++i)
        {
            int w = prefer[m][i];
            if (wPartner[w - n] == -1)
            {
                wPartner[w - n] = m;
                mFree[m] = false;
                freeCount --;   
            }

            else
            {
                int m1 = wPartner[w - n];
                if (wPrefersM1OverM(prefer, w, m1, m) == false)
                {
                    wPartner[w - n] = m;
                    mFree[m] = false;
                    mFree[m1] = true;
                }
            }
        }
    }

    // Print output
    cout << "Women\tMen" << endl;
    for (int i; i < n; ++i)
        cout << " " << n + i << "\t" << wPartner[i] << endl;
}

int main(){
    int prefer[2*n][n] = {
        {5, 4, 7, 6},
        {6, 4, 7, 5},
        {4, 5, 6, 7},
        {4, 7, 6, 5},

        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3}
    };

    stableMarrige(prefer);

    return 0;
}