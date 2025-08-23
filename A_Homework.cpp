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
        int m;
        cin >> m;
        string a, b;
        cin >> a >> b;
        string s1 = "";
        string s2 = "";
        for (int i = m-1; i>=0; i--)
        {
            if (b[i] == 'V')
                s1 += a[i];
            else
                s2 += a[i];
        }
        reverse( s2.begin() ,s2.end());
        cout << s1 + s + s2 << endl;
    }
    return 0;
}