#include <bits/stdc++.h>
using namespace std;

bool cycle = 0;
int a[1005][1005], visit[1005];

/*void DFS(int x, int n)
{
    cout << "DFS " << x << endl;
    visit[x] = 1;
    if (cycle) return;
    for (int i = 0 ; i < n ; i++ )
    {
        if (a[x][i])
        {
            if (!visit[i])
            {
                a[x][i] = 0;
                a[i][x] = 0;
                DFS(i,n);
                a[x][i] = 1;
                a[i][x] = 1;
            } else
            {
                cout << "cycle turn at" << x << endl;
                cycle = 1; return;
            }
        }
    }
    return;
}
*/

void DFS(int u,int n) {
    visit[u] = 1;
    for(int v = 0 ; v < n ; v++)
        if (a[u][v] && !visit[v]) DFS(v,n);
        else if (a[u][v] && visit[v]) cycle = 1;
    visit[u] = 2;
}

int main()
{
    int m ,n,i,j,t,bac;
    cin >> n >> m;


    for ( i = 0 ; i < n ; i ++ )
        for ( j = 0 ; j < n ; j++ )
        {
            a[i][j] = 0;
        }
        visit[i] = 0;

    for (i = 0 ; i < m ; i++)
    {
        cin >> j >> t;
        a[j][t] = 1;
        a[t][j] = 1;
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


/*
100 100
0 1
0 2
1 2
2 3
1 4
3 5
3 6
3 7
1 8
5 9
5 10
1 11
9 12
9 13
11 14
14 15
0 16
0 17
8 18
15 19
1 20
0 21
11 22
3 23
16 24
3 25
10 26
16 27
14 28
0 29
21 30
23 31
11 32
24 33
19 34
22 35
20 36
7 37
25 38
5 39
21 40
39 41
39 42
5 43
8 44
6 45
32 46
13 47
39 48
7 49
4 50
29 51
22 52
19 53
26 54
6 55
53 56
36 57
0 58
44 59
48 60
24 61
47 62
49 63
56 64
6 65
49 66
29 67
49 68
45 69
20 70
5 71
52 72
49 73
15 74
5 75
64 76
62 77
68 78
19 79
3 80
5 81
42 82
77 83
58 84
33 85
31 86
56 87
49 88
51 89
47 90
77 91
83 92
26 93
3 94
67 95
78 96
49 97
7 98
44 99*/
/*for ( i = 0 ; i < n ; i++)
    {
        for ( j = 0 ; j < n ; j++ )
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
