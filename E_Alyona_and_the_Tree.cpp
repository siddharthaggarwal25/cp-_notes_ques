#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<int> weight;
vector<int> size_;
void dfs(int node, int parent)
{
   
    for (auto child : adj[node])
    {
        if (child.first == parent)
            continue;
    
        dfs(child.first, node);
        size_[node ]  += size_[child.first] +1;
    }
   
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    weight.resize(n + 1);
    size_.assign(n + 1,0 );
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int u, w;
        cin >> u >> w;
        adj[u].push_back({i, w});
        adj[i].push_back({u, w});
    }
    dfs(1, 0);
     for( int i=1  ;i<= n  ;i++){
        cout<<size_[i]<<" ";
     }

        return 0;
}