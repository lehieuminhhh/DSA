#include <bits/stdc++.h>
using namespace std;

int gcf(int a, int b)
{
    if (a%b == 0)
    {
        return b;
    }
    return gcf(b,a%b);
}

int main()
{
    int a,b;
    cin >> a>> b;
    if (a>b)
    {
        cout << gcf(a,b);
        return 0;
    }
    cout << gcf(b,a);
    return 0;
}
