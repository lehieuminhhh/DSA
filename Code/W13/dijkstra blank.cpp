#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, i, sum = 1;

    cin >> n >> a >> b;
    int G[n][n];
    int S[n], Len[n], P[n];

    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
            sum += G[i][j];
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && G[i][j] == 0)G[i][j] = sum;
        }
    }
    a--;
    b--;

    for (int i = 0; i < n; i++)
    {
        Len[i] = sum;
        S[i] = 0;
        P[i] = a;
    }
    Len[a] = 0;

    //for (int k = 0; k < n; k++)
    while (S[b] == 0)
        {
        for (i = 0; i < n; i++)
        {
            if (!S[i] && Len[i] < sum) break;
        }

        if (i >= n) break;

        for (int j = 0; j < n; j++)
        {
            if (!S[j] && Len[i] > Len[j]) i = j;
        }

        S[i] = 1;

        for (int j = 0; j < n; j++)
        {
            if (!S[j] && Len[i] + G[i][j] < Len[j])
            {
                Len[j] = Len[i] + G[i][j];
                P[j] = i;
            }
        }
    }
    /*if (Len[b] > 0 && Len[b] < sum) {
        fprintf(fo, "Length of %d to %d is %d\n", a + 1, b + 1, Len[b]);

        // truy vet
        while (i != a) {
            fprintf(fo, "%d <-- ", i + 1);
            i = P[i];
        }
        fprintf(fo, "%d", a + 1);
    } else {
        fprintf(fo, "khong co duong di tu %d den %d\n", a + 1, b + 1);
    }*/
    for (i = 0 ; i < n ; i++ )
    {
        cout << Len[i] << " ";
    }
    return 0;
}

/*5 1 5
0 10 10 33 0
10 0 0 20 0
10 0 0 25 0
33 20 25 0 0
0 0 0 0 0*/

