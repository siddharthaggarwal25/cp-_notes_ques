// #include <bits/stdc++.h>
// using namespace std;
// #define pb push_back
// #define int long long
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define test  \
//     int _;    \
//     cin >> _; \
//     for (int tt = 1; tt <= _; tt++)
// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// bool withInBounds(int i, int j, int n, int m)
// {
//     return i >= 0 and j >= 0 and i < n and j < m;
// }
// int32_t main()
// {

//     fastio;
//     // code goes here
//     test
//     {
//         int n, m;
//         cin >> n >> m;
//         vector<string> a(n);
//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         deque<pair<int, int>> d;
//         d.push_back({0, 0});

//         int dx[4] = {1, -1, 0, 0};
//         int dy[4] = {0, 0, 1, -1};
//         int inf = 1000000;
//         vvi cost(n, vi(m, inf));
//         cost[0][0] = 0;
//         while (!d.empty())
//         {
//             auto u = d.front();
//             d.pop_front();
//             int i = u.first;
//             int j = u.second;
//             for (int k = 0; k < 4; k++)
//             {
//                 int x = i + dx[k];
//                 int y = j + dy[k];

//                 if (withInBounds(x, y, n, m))
//                 {
//                     if (a[x][y] == a[i][j] and cost[x][y] > cost[i][j])
//                     {
//                         d.push_front({x, y});
//                         cost[x][y] = cost[i][j];
//                     }
//                     else if (cost[x][y] > cost[i][j] + 1)
//                     {

//                         d.push_back({x, y});
//                         cost[x][y] = cost[i][j] + 1;
//                     }
//                 }
//             }
//         }
//         cout << cost[n - 1][m - 1] << "\n";
//     }
// }
