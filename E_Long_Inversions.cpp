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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = s[i] - '0';
        }
        for (int i=1; i <=n ; i++ )
        {
            int flag = 0;
            int k = i;
            for (int j = 0; j < n; j++)
            {
                if ((v[j] == 1 && flag % 2 == 0) || (v[j] == 0 && flag % 2 == 1))
                {
                    continue;
                }else{
                    flag ++;

                }
            }
        }
    }
    return 0;
}