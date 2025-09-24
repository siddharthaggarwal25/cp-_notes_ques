#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a] = 1;
        v[b] = 1;
    }
    int node;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            node = i;
            break;
        }
    }

    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i != node)
            cout << i << " " << node << endl;
    }

    return 0;
}