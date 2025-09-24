#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> v[i];
        }
        cout << -v[0] + v[1] - v[2] - v[3] + v[4] + v[5] - v[6] + v[7] << endl;
    }
    return 0;
}