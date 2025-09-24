#include <bits/stdc++.h>
using namespace std;
#define int long long 

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{

    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs(child, vis, adj, st);
    }
    st.push(node);
}
void dfs2(int node, vector<int> &vis, vector<vector<int>> &adj)
{

    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs2(child, vis, adj);
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1), adjt(n + 1);
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    vector<int >notconn;
    stack<int> st;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis1[i] == 0)
        {
            dfs(i, vis1, adj, st);
        }
    }


    // cout<<"fewf";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if( vis2[node]==0){
            notconn.push_back( node);
             dfs2( node, vis2, adjt);
        }
    }


    if( notconn.size() ==1 ){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
          cout<< notconn[1] <<" "<<notconn[0]<<endl;
        
    }


    return 0;
}