#include <bits/stdc++.h>
using namespace std;

bool BSTcheck (int *a,int start, int last)
{
    if (start>=last)
    {
        return 1;
    }
    int key = a[start],i,j;
    if (a[start+1]>a[start])
    {
        i=start+1;
        while (i<=last && a[i]>a[start])
        {
            i++;
        }
        j=i;
        while(j<=last && a[j]<a[start])
        {
            j++;
        }
        if (BSTcheck(a,start+1,i-1) & BSTcheck(a,i,j-1) & j==last+1)
        {
            cout << endl << start << " " << last << " " << 1;
            return 1;
        } else
        {
            cout << endl << start << " " << last << " " << 0;
            return 0;
        }
    }
    if (a[start+1]<a[start])
    {
        i=start+1;
        while (i<=last && a[i]<a[start])
        {
            i++;
        }
        j=i;
        while(j<=last && a[j]>a[start])
        {
            j++;
        }
        if (BSTcheck(a,start+1,i-1) & BSTcheck(a,i,j-1) & j==last+1)
        {
            cout << endl << start << " " << last << " " << 1;
            return 1;
        } else
        {
            cout << endl << start << " " << last << " " << 0;
            return 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> a[i];
    }
    if (BSTcheck(a,0,n-1))
    {
        cout << "yes";
        return 0;
    }
    cout << "no";
    return 0;
}

//9 13 4 3 5 6 7 9 24 35
