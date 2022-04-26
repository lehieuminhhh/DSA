#include <bits/stdc++.h>
using namespace std;

typedef struct group
{
    int size;
    vector<int> arr;

    group()
    {
        this->size = 0;
    }
    group (int n,vector<int> array )
    {
        this->size = n;
        this->arr = array;
    }

    print()
    {
        for (int i = 0 ; i < size ; i++ )
        {
            cout << arr[i] << " ";
        }
    }

    add (int val, int pos)
    {
        arr.insert(arr.begin()+pos-1 , val);
    }

    intersection (group x)
    {
        vector <int> a,b;
        a = this->arr;
        b = x.arr;
        int i;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        i = 1;
        while (i<a.size())
        {
            if (a[i] == a[i-1])
            {
                a.erase(a.begin()+i);
            } else
            {
                i++;
            }
        }
        i = 1;
        while (i<b.size())
        {
            if (b[i] == b[i-1])
            {
                b.erase(b.begin()+i);
            } else
            {
                i++;
            }
        }
        a.insert(a.begin(),b.begin(),b.end());
        sort(a.begin(), a.end());
        for ( i = 1 ; i < a.size(); i++)
        {
            if (a[i] == a[i-1])
            {
                cout << a[i] <<" ";
            }
        }
    }
}Group;


int main()
{
    int n , i, temp;
    vector<int> array;


    cin >> n;
    for ( i = 0 ; i < n ; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    Group g1(n,array);
    array.clear();
    cin >> n;
    for ( i = 0 ; i < n ; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    Group g2(n,array);
    g1.intersection(g2);

    return 0;
}
