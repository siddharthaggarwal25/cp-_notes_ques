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
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        bool ans = true;
        for (int i = 1; i < n; i++)
        {   if( v[i] < 0) {
            ans= false;
            break;
        }
            if ((v[i + 1] >= v[i - 1]) && (v[i] >= 2 * v[i - 1]))
            {
                v[i + 1] -= v[i - 1];
                v[i] -= (2 * v[i - 1]);
                v[i - 1] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (v[i] != 0)
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}