#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
        degree[x]++;
        degree[y]++;
    };
    string s = "";
    for (auto i : edges)
    {
        if (degree[i.first] > 1 && degree[i.second] > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        else
        {
            if (degree[i.first] == 1)
            {
                s += '0';
            }
            else
            {
                s += '1';
            }
        }
    }
    cout << "YES" << endl;
    cout << s << endl;
    return 0;
}