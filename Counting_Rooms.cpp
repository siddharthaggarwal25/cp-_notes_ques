#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && v[i][j] == '.')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty())
                {

                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int newx = x + dx[k];
                        int newy = y + dy[k];
                        if (newx >= 0 && newy >= 0 && newx < n && newy < m && v[newx][newy] == '.' && vis[newx][newy] == 0)
                        {
                            vis[newx][newy] = 1;
                            q.push({newx, newy});
                        }
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}