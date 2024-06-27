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
        int ans = 0;
        for (int i = 1; i < n ; i++)
        {
            if (s[i-1] == '*' && s[i] == '*')
            {
                break;
            }

            if (s[i] == '@')
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}