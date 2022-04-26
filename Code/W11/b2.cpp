#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> a;
    int n,i,t;
    cin>> n;
    for ( i = 0 ;  i < n  ; i++ )
    {
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    cout << a[(a.size()-1)/2];
    return 0;
}
