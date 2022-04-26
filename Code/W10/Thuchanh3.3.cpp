#include <bits/stdc++.h>
using namespace std;

int main()
{
    int prime[20] = {2,3,5,7,11,13,17,19,23,29,31,37,43,47,53,59,61,67,71};
    int n,i,q,t,task;
    cin >> n >> q;
    vector <int> a,b,c;
    for ( i = 0 ; i < n ; i ++)
    {
        cin >> t;
        a.push_back(t);
    }
    for (task = 0; task < q; task ++)
    {
        c.clear();
        b.clear();
        for ( i = a.size()-1 ; i>= 0; i--)
        {
            if (a[i]%prime[task]==0)
            {
                b.push_back(a[i]);
            } else
            {
                c.push_back(a[i]);
            }
        }
        a=c;
        t=b.size();
        for ( i = b.size()-1 ; i>= 0; i-- )
        {
            cout << b[i] <<endl;
        }
    }
    for ( i = c.size()-1 ; i>= 0; i-- )
    {
        cout << c[i] <<endl;
    }
    return 0;
}
