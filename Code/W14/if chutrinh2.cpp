#include <bits/stdc++.h>
using namespace std;

bool cycle = 0;
int a[1005][1005], visit[1005];


void DFS  (int x, int n)
{
    if (cycle) return;
    visit[x] = 1;
    for (int i = 0 ; i < n ; i++)
    {
        if(a[x][i]==1)
        {
            if(!visit[i])
            {
                a[x][i] = 2;
                a[i][x] = 2;
                DFS(i,n);
            } else
            {
                cycle = 1;
                return;
            }
        }
    }
    return;
}

int main()
{
    int m ,n,i,t;
    cin >> n >> m;


    for ( i = 0 ; i < n ; i ++ )
        for ( int j = 0 ; j < n ; j++ )
        {
            a[i][j] = 0;
        }
        visit[i] = 0;

    for (int j = 0 ; j < m ; j++)
    {
        cin >> i >> t;
        a[i][t] = 1;
        a[t][i] = 1;
    }

    i = 0;
    while (!cycle && i<n)
    {
        if (!visit[i])
        {
            DFS(i,n);
        }
        i++;
    }
    if (cycle)
    {
        cout << "YES";
        return 0;
    }
    cout <<"NO";
    return 0;
}
