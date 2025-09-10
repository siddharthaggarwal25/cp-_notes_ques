#include <bits/stdc++.h>
using namespace std;
#define int long long
int v[2025][2025];
int32_t main()
{
    vector<int> pre(2025, 0);

    for (int i = 1; i <= 2023; i++)
    {
        pre[i] = i + pre[i - 1];
    }

    for (int i = 1; i <= 2023; i++)
    {
        int start = pre[i - 1];
        for (int j = 1; j <= i; j++)
        {

            v[i][j] = (start + j) * (start + j)*1ll;
            v[i][j] = (v[i][j]+ v[i - 1][j - 1]);
            v[i][j] = (v[i][j] +v[i - 1][j]);
        }
    }

     int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int ind = lower_bound(pre.begin(), pre.end(), n) - pre.begin();
        int x = ind;
        int y = n - pre[ind - 1];

        // cout << v[x][y] << endl;
    }

    cout << "----------" << endl;

    for (int i = 0; i < 10 ; i++)
    {
        
        for (int j = 0; j < 13; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}