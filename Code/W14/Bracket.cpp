/*Cho một xâu kí tự chỉ gồm các ký tự '(',')','*'. Kiểm tra xâu kí tự này phải là dãy ngoặc hợp lệ khộng.

Chú thích: Ký tự '*' có thể thay thể cho một ký tự '(' hoặc ')' hoặc một xâu rỗng

Đầu vào: Dòng đầu tiên chứa số nguyên n là số lượng xâu ký tự cần kiểm tra. n dòng tiếp theo, mỗi dòng chứa một xâu ký tự cần kiểm tra. (n≤10, độ dài các xâu không vượt quá 10000).

Đầu ra: Gồm n dòng, mỗi dòng tương ứng in ra yes nếu xâu ký tự đó là dãy ngoặc hợp lệ và no nếu ngược lại.*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    stack<char> bracHolder, temp;
    char c;
    string s;
    bool valid = 1;
    int i,l;

    cin >> s;
    l = s.length();
    for (i = 0 ; i < l ; i++)
    {
        if (s[i] == '(' || s[i] == '*') bracHolder.push(s[i]);
        if (s[i] == ')')
        {

            while (1)
            {
                if (!bracHolder.empty())
                {
                    c = bracHolder.top();
                    if (c == '(')
                    {
                        bracHolder.pop();
                        while (!temp.empty())
                        {
                            temp.pop();
                            bracHolder.push('*');
                        }
                        break;
                    }
                    if (c == '*')
                    {
                        bracHolder.pop();
                        temp.push('*');
                    }
                } else
                {
                    if (temp.empty())
                    {
                        cout << "no" << endl;
                        return;
                    } else
                    {

                        temp.pop();
                        while (!temp.empty())
                        {
                            temp.pop();
                            bracHolder.push('*');
                        }
                        break;
                    }
                }

            }
        }
    }
    /*while (!bracHolder.empty())
    {
        cout << bracHolder.top();
        bracHolder.pop();
    }
    cout << endl;
    while (!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }*/
    while (!bracHolder.empty())
    {
        c = bracHolder.top();
        bracHolder.pop();
        if (c == '*') temp.push('*');
        if (c == '(')
        {
            if (temp.empty())
            {
                cout << "no" << endl;
                return;
            } else
            {
                temp.pop();
            }
        }
    }
    cout <<"yes"<<endl;
    return;
}

int main()
{
    int q;
    cin >> q;

    for (int i = 0 ; i < q ; i++ )
    {
        solve();
    }
    return 0;
}
