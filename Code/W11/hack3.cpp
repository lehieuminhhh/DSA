#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i , n , t;
    vector <int> a;
    cin >> n;
    for ( i = 0 ; i < n ; i++ )
    {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    t = a[1]-a[0];
    for ( i = 2; i< n; i++ )
    {
        if (a[i] - a[i-1] < t)
        {
            t = a[i]-a[i-1];
        }
    }
    for ( i = 1; i< n ;i++ )
    {
        if ((a[i] - a[i-1])==t)
        {
            cout << a[i-1] << " " << a[i] << " ";
        }
    }
    return 0;
}
