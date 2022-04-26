#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin >> n;
    if (n == 0)
    {
        cout<<"yes";
        return 0;
    }
    vector <vector<int>> a(n-1 , vector<int>(2));
    for (i = 0 ; i < n-1 ; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    if (log2(n+1)!= round(log2(n+1)))
    {
        cout <<"no";
        return 0;
    }
    sort(a.begin(),a.end());
    for ( i = 0 ; i < n-1 ; i++)
    {
        if (a[i][0] != trunc(i/2))
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}
