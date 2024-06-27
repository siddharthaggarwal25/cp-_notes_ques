// #include <bits/stdc++.h>
// using namespace std;
// const int N = 6e4 + 5;
// int n, k, ans;
// vector<vector<int>> adj;
// int dp[N][501];
// void dfs(int node, int parent)
// {
//     for (auto child : adj[node])
//     {
//         if (child == parent) continue;
//         dfs(child, node);
//         for (int i = 1; i <= k; i++)
//         {
//             ans += dp[child][i - 1] * dp[node][k - i];
//         }
//         for (int i = 1; i <= k; i++)
//         {
//             dp[node][i] += dp[child][i - 1];
//         }
//     }
// }
// int32_t main()
// {
//     cin >> n >> k;
//     adj.resize(n + 1);
//     for (int i = 0; i < n - 1; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     int start = 0;
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 1;
//     }
//     dfs(1, -1);
//     cout << ans << endl;

//     // ends
// }

#include<bits/stdc++.h>
using namespace std;
int  main (){
     int a  =  1024 ;
     int b =   64;
     cout<<a&b<<endl;
return 0;
}