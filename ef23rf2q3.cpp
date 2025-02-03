#include <bits/stdc++.h>
using namespace std;
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool isValid(int x, int y, int n, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    return x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1 && !visited[x][y];
}

set<pair<int, int>> getRegion(int startX, int startY, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    set<pair<int, int>> region;
    int n = grid.size();
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        region.insert({x, y});

        for (auto it : directions)
        {
            int dx = it.first;
            int dy = it.second;
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(newX, newY, n, grid, visited))
            {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return region;
}

int countMatches(vector<string> &grid1, vector<string> &grid2)
{
    int n = grid1.size();
    vector<vector<int>> matrix1(n, vector<int>(n)) ,  matrix2(n, vector<int>(n));
    vector<vector<bool>> visited1(n, vector<bool>(n, false)) ,  visited2(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix1[i][j] = grid1[i][j] - '0';
            matrix2[i][j] = grid2[i][j] - '0';
        }
    }
    vector<set<pair<int, int>>> regions1, regions2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix1[i][j] == 1 && !visited1[i][j])
            {
                regions1.push_back(getRegion(i, j, matrix1, visited1));
            }
            if (matrix2[i][j] == 1 && !visited2[i][j])
            {
                regions2.push_back(getRegion(i, j, matrix2, visited2));
            }
        }
    }
    int matchCount = 0;
    for (auto region1 : regions1)
    {
        for (auto region2 : regions2)
        {
            if (region1 == region2)
            {
                matchCount++;
                break;
                
            }
        }
    }

    return matchCount;
}

int main()
{
    int n;
    cin >> n;
    vector<string> grid1(n), grid2(n);
    for (int i = 0; i < n; i++)
        cin >> grid1[i];
    for (int i = 0; i < n; i++)
        cin >> grid2[i];

    cout << countMatches(grid1, grid2) << endl;
    return 0;
}
