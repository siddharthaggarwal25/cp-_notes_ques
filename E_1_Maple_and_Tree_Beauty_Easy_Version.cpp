#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int height, vector<vector<int>> &depth, vector<int> &isleaf, vector<vector<int>> &adj)
{
    depth[height].push_back(node);

    if (adj[node].size() == 0)
        isleaf[node] = 1;
    for (auto child : adj[node])
    {
        dfs(child, height + 1, depth, isleaf, adj);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
        vector<vector<int>> depth(n);
        vector<int> isleaf(n + 1, 0);
        dfs(1, 0, depth, isleaf, adj);

        // for( int i =0  ;i<n ;i++){
        //     for( auto it: depth[i])cout<<it<<" ";
        //     cout<<endl;
        // }

        // for( int i=1  ;i<= n ;i++)cout<<isleaf[i]<<" ";
        int cnt = 0;
        int zeros = k;
        int ones = n - k;

        for (int i = 0; i < n; i++)
        {
            bool temp = false;
            for (auto it : depth[i])
            {
                if (isleaf[it] == 1)
                    temp = true;
            }
            int s = depth[i].size();

            if (ones > zeros)
                swap(zeros, ones);

            if (s <= ones)
            {
                cnt++;
                ones -= s;
            }
            else if (s <= zeros)
            {
                cnt++;
                zeros -= s;
            }

            if (temp)
                break;
        }

        cout << cnt << endl;
    }
    return 0;
}