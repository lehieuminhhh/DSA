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
    if (n%2 ==0)
    {
        cout <<"no";
        return 0;
    }
    if (n == 3)
    {
        if (a[0][0] == a[1][0])
        {
            cout <<"yes";
        } else
        {
            cout<<"no";
        }
        return 0;
    }
    sort(a.begin(),a.end());
    int s,prev;
    prev = a[0][0];
    s = 1;
    for (i = 1 ; i < n-1 ; i++)
    {
        if (a[i][0]==prev)
        {
            s++;
        } else
        {
            if (s==1 || s==3)
            {
                cout<<"no";
                return 0;
            } else
            {
                s = 1;
            }
        }
        prev = a[i][0];
    }
    cout << "yes";
    return 0;
}

