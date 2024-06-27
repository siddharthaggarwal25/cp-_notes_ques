#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string str = s;
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;

        int a = 0;
        int b = str.length() - 1;

        bool check = true;

        while (a < b)
        {
            if (str[a] == str[b])
            {
            }
            else if (str[a] < str[b])
            {
                break;
            }
            else
            {
                check = false;
                break;
            }

            a++;
            b--;
        }

        if (check)
        {
            cout << s1 << endl;
        }
        else
        {
            cout << s2 + s1 << endl;
        }
    }
    return 0;
}