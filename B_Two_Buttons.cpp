#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(2 * 1e4);
    for (int i = 1; i < 2 * 1e4; i++)
    {
        int cur = i;
        if (i - 1 > 0)
            adj[i].push_back(i - 1);
        if (2 * i < 2e4)
            adj[i].push_back(2 * i);
    }

    vector<int> vis(2 * 1e4 + 1, 0);
    vector<int> dis(2 * 1e4 + 1, 1e8);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n});
    dis[n] = 0;
    vis[n]= 1;
    while( !pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for( auto child : adj[node]){
            if( dis[child] >  1 +  distance ){
                dis[child ] = 1  + distance ;
                pq.push( { dis[child ] , child});
                vis[child ] = 1; 
            }
        }
    }
    cout<<dis[m]<<endl;

    return 0;
}