#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> matrix(1001, vector<char>(1001));
vector<vector<int>> vis(1001, vector<int>(1001, 0));
vector<vector<pair<char, pair<int, int>>>> parent(1001, vector<pair<char, pair<int, int>>>(10001));
int n, m;
bool isValid(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= n && y <= m)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    int x0, y0, x1, y1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
            {
                x0 = i;
                y0 = j;
            }
            if (matrix[i][j] == 'B')
            {
                x1 = i;
                y1 = j;
            }
        }
    }
    int xi[] = {1, -1, 0, 0};
    int yi[] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    q.push({x0, y0});
    vis[x0][y0] = 1;

    parent[x0][y0] = {'O', {x0, y0}};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newx = x + xi[i];
            int newy = y + yi[i];

            if (isValid(newx, newy) && !vis[newx][newy] && (matrix[newx][newy] != '#'))
            {
                q.push({newx, newy});
                vis[newx][newy] = 1;
                if (i == 0)
                    parent[newx][newy] = {'D', {x, y}};
                else if (i == 1)
                    parent[newx][newy] = {'U', {x, y}};
                else if (i == 2)
                    parent[newx][newy] = {'R', {x, y}};
                else if (i == 3)
                    parent[newx][newy] = {'L', {x, y}};
            }
        }
    }

    if (!vis[x1][y1])
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

   vector<char >ans ;

    while ((x1 != x0) || (y1 != y0))
    {
        ans.push_back(parent[x1][y1].first);
        int a = parent[x1][y1].second.first;
        int b = parent[x1][y1].second.second;
        x1 = a;
        y1 = b;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }

    return 0;
}
