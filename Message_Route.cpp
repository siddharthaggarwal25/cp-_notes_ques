#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dis(n + 1, 1e9);
    dis[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 1});
    vector<int > parent( n+1 );
    for( int i =0  ;i<= n ;i++)parent[i] = i ;

    while (!pq.empty())
    {
        int curdis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto child : adj[node])
        {
            if (dis[child] > curdis + 1)
            {
                dis[child] = curdis + 1;
                pq.push({curdis + 1, child});
                parent[child] = node;
            }
        }
    }

    if ( dis[n] == 1e9){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
          cout<<dis[n]<<endl;
          stack<int > st ;
           int node = n ;
          while(parent[node] != node ){
            st.push( node);
            node = parent[node];
          }
          st.push( 1 );
          while( !st.empty()){
            cout<<st.top()<<" ";
            st.pop();
          }

    }
    return 0;
}