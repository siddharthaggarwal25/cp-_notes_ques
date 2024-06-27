#include <bits/stdc++.h>
using namespace std;
#define int long long

int xi[] = {-1, 1, 0, 0};
int yi[] = {0, 0, 1, -1};
int par[1005][1005];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &i : grid)
        cin >> i;
    queue<pair<int, int>> q;
    int x, y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'M')
                q.push({i, j});
            else if (grid[i][j] == 'A')
                x = i, y = j;

    q.push({x, y});
    par[x][y] = -1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newx = x + xi[i],
                newy = y + yi[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m || grid[newx][newy] != '.')
                continue;
            else
            {
                grid[newx][newy] = grid[x][y];
                if (grid[newx][newy] == 'A') par[newx][newy] ='A';
                q.push({newx, newy});
            }
        }
    }
   for( auto i : grid){
    for( auto j : i ){
        cout<<j<<" ";
    }
    cout<<endl;
   }
}
int32_t main()
{
    solve();
    return 0;
}