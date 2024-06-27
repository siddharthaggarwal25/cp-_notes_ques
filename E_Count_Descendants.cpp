#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> depth;
vector<int> par;
// vector< vector<int >> adj;
void dfs(int node, int parent)
{

    for (auto child : adj[node])
    {
        par[child] = node;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    depth.assign(n + 1, 0);
    par.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " " << depth[i] << " "<<par[i];
    //     cout << endl;
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int u, d;
        vector<vector<int>> component;
        for (int i = 1; i <= n; i++)
        {
            if (depth[i] == d)
            {
                int val = i;
                vector<int > comp ;
                while (val != 0)
                {
                    comp.push_back( val);
                    val = par[val];
                }

                for( auto x  : comp ){
                    if( x== u){
                        component.push_back( comp);
                        break;
                    }
                }
                
            }`

        }
    }

    return 0;
}