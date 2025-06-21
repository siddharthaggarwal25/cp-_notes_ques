#include <bits/stdc++.h>
using namespace std;

int manhattanDistance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int x, int y, int ex, int ey, int n, vector<vector<int>> &holes, int mask)
{
    // Base case: reached destination
    if (x == ex && y == ey)
        return 0;

    // All portals used, can't teleport anymore
    if (mask == (1 << n) - 1)
        return manhattanDistance( x, y, ex, ey);

    // Direct move to destination
    int minCost = manhattanDistance(x, y, ex, ey);

    for (int i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newMask = mask | (1 << i);

            // Use portal from entry1 -> exit2
            int cost1 = manhattanDistance(x, y, holes[i][0], holes[i][1]) + holes[i][4];
            cost1 += solve(holes[i][2], holes[i][3], ex, ey, n, holes, newMask);

            // Use portal from entry2 -> exit1
            int cost2 = manhattanDistance(x, y, holes[i][2], holes[i][3]) + holes[i][4];
            cost2 += solve(holes[i][0], holes[i][1], ex, ey, n, holes, newMask);

            minCost = min({minCost, cost1, cost2});
        }
    }

    return minCost;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        vector<vector<int>> holes(n, vector<int>(5));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> holes[i][j];

        int ans = solve(sx, sy, ex, ey, n, holes, 0);
        cout << ans << endl;
    }
    return 0;
}


