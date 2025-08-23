#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'A') start = {i, j};
            if (v[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> path(n, vector<int>(m, -1));

    int dx[4] = {1, -1, 0, 0};      
    int dy[4] = {0, 0, 1, -1};
    char move[4] = {'D', 'U', 'R', 'L'};

    q.push(start);
    vis[start.first][start.second] = 1;
    path[start.first][start.second] = 5;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] &&
                (v[nx][ny] == '.' || v[nx][ny] == 'B')) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
                path[nx][ny] = i; 
            }
        }
    }

    if (!vis[end.first][end.second]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<char> ans;
        while (path[end.first][end.second] != 5) {
            int dir = path[end.first][end.second];
            ans.push_back(move[dir]);
            end.first -= dx[dir];
            end.second -= dy[dir];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (char c : ans) cout << c;
        cout << "\n";
    }

    return 0;
}
