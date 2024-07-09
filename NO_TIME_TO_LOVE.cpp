#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m - 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(n - 1, vector<int>(m));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int distance = pq.top().first;
        pq.pop();

        if (y + 1 < m && (dis[x][y + 1] > distance + a[x][y]))
        {
            dis[x][y + 1] = distance + a[x][y];
            pq.push({dis[x][y + 1], {x, y + 1}});
        }

        if (y - 1 >= 0 && (dis[x][y - 1] > distance + a[x][y - 1]))
        {
            dis[x][y - 1] = distance + a[x][y - 1];
            pq.push({dis[x][y - 1], {x, y - 1}});
        }

        if (x + 1 < n && (dis[x + 1][y] > distance + b[x][y]))
        {
            dis[x + 1][y] = distance + b[x][y];
            pq.push({dis[x + 1][y], {x + 1, y}});
        }

        for (int i = 1; i <= x; i++)
        {
            if ( (dis[x - i][y] > distance + i+1))
            {
                dis[x - i][y] = distance + i+1;
                pq.push({dis[x - i][y], {x - i, y}});
            }
        }
    }
    cout << dis[n-1][m-1] << endl;

    return 0;
}