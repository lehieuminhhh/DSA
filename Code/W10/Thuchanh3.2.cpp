#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,task,t,i,j,mx;
    vector <int> custID;
    vector <int> custPri;
    n = 0;
    while (cin>> task)
    {
        switch(task)
        {
            case 0:
                return 0;
            case 1:
            {
                n++;
                cin>>t;
                custID.push_back(t);
                cin>>t;
                custPri.push_back(t);
                break;
            }
            case 2:
            {
                if (n ==0 )
                {
                    cout<< "0"<<endl;
                    break;
                }
                mx =0;
                for (j = 0; j < n ; j++)
                {
                    if (custPri[j]>custPri[mx])
                    {
                        mx = j;
                    }
                }
                cout << custID[mx]<<endl;
                n--;
                custID.erase(custID.begin()+mx);
                custPri.erase(custPri.begin()+mx);
                break;
            }
            case 3:
            {
                if (n ==0 )
                {
                    cout<< "0"<<endl;
                    break;
                }
                mx =0;
                for (j = 0; j < n ; j++)
                {
                    if (custPri[j]<custPri[mx])
                    {
                        mx = j;
                    }
                }
                cout << custID[mx]<<endl;
                n--;
                custID.erase(custID.begin()+mx);
                custPri.erase(custPri.begin()+mx);
                break;
            }
        }
    }
    return 0;
}
