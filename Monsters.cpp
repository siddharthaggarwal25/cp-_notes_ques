#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char moveChar[4] = {'D', 'U', 'R', 'L'};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    queue<pair<int, int>> q;
    pair<int, int> start, end = {-1, -1};
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    vector<vector<int>> dis2(n, vector<int>(m, 1e9));
    map<pair<int, int>, pair<pair<int, int>, char>> par;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];

            if (adj[i][j] == 'M')
            {
                q.push({i, j});
                dis[i][j] = 0;
            }

            if (adj[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 && newy >= 0 && newx < n && newy < m && adj[newx][newy] != '#' && (dis[newx][newy] > dis[x][y] + 1))
            {
                dis[newx][newy] = dis[x][y] + 1;
                q.push({newx, newy});
            }
        }
    }
    par[start] = {{start}, 'Q'};
    q.push(start);
    dis2[start.first][start.second] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        {
            end = {x, y};
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 && newy >= 0 && newx < n && newy < m && adj[newx][newy] != '#' && dis2[newx][newy] == 1e9 && (dis2[x][y] + 1 < dis[newx][newy]))
            {
                dis2[newx][newy] = dis2[x][y] + 1;
                par[{newx, newy}] = {{x, y}, moveChar[i]};
                q.push({newx, newy});
            }
        }
    }

    if (end.first == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        stack<char> path;
        for (auto i = end; i != start; i = par[i].first)
        {
            path.push(par[i].second);
        }
        cout << "YES" << endl;
        cout << path.size() << endl;
        while (!path.empty())
        {
            cout << path.top();
            path.pop();
        }
    }

    return 0;
}