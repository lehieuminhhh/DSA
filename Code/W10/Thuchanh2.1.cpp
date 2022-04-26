#include <bits/stdc++.h>
using namespace std;

int main ()
{
    stack <int> s;
    int n,t,i;
    cin >> n;
    string str;

    for ( i = 0 ; i < n ; i ++ )
    {
        cin >> str;
        if (str == "INS")
        {
            cin >> t;
            s.push(t);
        }
        if (str == "DBL")
        {
            s.top() = s.top() * 2;
        }
        if (str == "POP")
        {
            cout << s.top() << endl;
            s.pop();
        }
    }

    return 0;
}
