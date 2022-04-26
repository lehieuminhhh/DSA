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
    if (n<4)
    {
        cout <<"yes";
        return 0;
    }
    sort(a.begin(),a.end());
    for (i = 0 ; i < n-3 ; i++)
    {
        if (a[i][0] == a[i+1][0] && a[i+1][0] == a[i+2][0])
        {
            cout <<"no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}
