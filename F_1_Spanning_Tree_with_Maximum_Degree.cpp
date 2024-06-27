#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        indegree[x]++;
        indegree[y]++;
    }
    int max_in_node = max_element( indegree.begin() , indegree.end())- indegree.begin();
    queue< int > q ;
    q.push( max_in_node);
    vector< int > vis ( n+1 , 0 );
    vis[max_in_node] = 1 ;
    vector<pair<int , int >> ans;
    while( !q.empty()){
        int node = q.front();
        q.pop();
        for( auto child  : adj [ node]){
            if( ! vis[child ]){
                vis[child  ]= 1 ;
                q.push( child );
                ans .push_back( { node , child });
            }
        }
    }
    for( auto i: ans ){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}