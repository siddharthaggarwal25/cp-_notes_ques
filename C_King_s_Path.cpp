#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    while (n--)
    {
        int u, v, w;
        cin >> w >> u >> v;
        int a = min(u, v);
        int b = max(u, v);
        for (int i = a; i <= b; i++)
        {
            mp[{w, i}] = 1;
        }
    }
    int xi[] = {-1, 1, 0, 0, 1, 1, -1, -1};
    int yi[] = {0, 0, -1, 1, 1, -1, 1, -1};

    queue<pair<int, int>> q;
    map<pair<int, int>, int> vis;
    map<pair<int, int>, int> dis;
    q.push({x, y});
    vis[{x, y}] = 1;
    dis[{x, y }] = 0;
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int newx = row + xi[i];
            int newy = col + yi[i];

            if (newx >= 1 && newy >= 1 && newx <= 1e9 && newy <= 1e9 && vis[{newx, newy}] == 0 && mp[{newx, newy}] == 1)
            {
                q.push({newx, newy});
                vis[{newx, newy}] = 1;
                dis[{newx, newy}] = dis[{ row, col }] +1 ;
            }
        }
    }

    if (vis[{x1, y1}])
        cout <<dis[{x1 , y1}]<< endl;
    else
    {
        cout << -1 << endl;
    }
    return 0;
}