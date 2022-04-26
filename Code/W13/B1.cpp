#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,a,b,i,j,u,v,w,sum=1;
    cin >> n >> m >> a ;
    int g[n][n];

    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < n ; j++ )
        {
            g[i][j] = 0;
        }
    }

    for ( i = 0 ; i < m ; i++ )
    {
        cin >> u >> v >> w;
        g[u-1][v-1] = w;
        g[v-1][u-1] = w;
        sum+=g[u-1][v-1];
    }
    int len[n],s[n],p[n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && g[i][j] == 0) g[i][j] = sum;
        }
    }
    a--;
    b--;

    for (int i = 0; i < n; i++)
    {
        len[i] = sum;
        s[i] = 0;
        p[i] = a;
    }
    len[a] = 0;
    for (int k = 0; k < n; k++)
        {
        for (i = 0; i < n; i++)
        {
            if (!s[i] && len[i] < sum) break;
        }

        if (i >= n) break;

        for (int j = 0; j < n; j++)
        {
            if (!s[j] && len[i] > len[j]) i = j;
        }

        s[i] = 1;

        for (int j = 0; j < n; j++)
        {
            if (!s[j] && len[i] + g[i][j] < len[j])
            {
                len[j] = len[i] + g[i][j];
                p[j] = i;
            }
        }
    }
    a = len[0];
    for (i = 1 ; i < n ; i++ )
    {
        if (len[i] > a && len[i] < sum)
        {
            a = len[i];
        }
    }
    cout << a;
    return 0;
}
