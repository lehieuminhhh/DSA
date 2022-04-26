#include <bits/stdc++.h>
using namespace std;


void haha()
{
    static int k = 0;
    k++;
}

int main()
{
    haha();
    haha();
    cout <<k;
    return 0;
}
