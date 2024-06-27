// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int n, m, q;

// vector<vector<pair<int, int>>> g;
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// vector<int> dis;
// const int inf = 1e18;

// int dfs(int start, int end)
// {
//     dis.assign( n+1 , inf );
//     pq.push({0 , start});
//     dis[start]= 0 ;
//     while( !pq.empty()){
//         int distance =  pq.top().first;
//         int node = pq.top().second ;
//         pq.pop();
//         for( auto child : g[node]){
//             int childNode = child.first;
//             int  weight = child.second;
//             if( dis[ childNode] > distance + weight){
//                 dis[childNode] = distance + weight;
//                 pq.push({ dis[childNode ]  , childNode});
//             }
//         }
//     }
//     return dis[end];
// }
// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >> n >> m >> q;
//     g.resize(n + 1);
//     for (int i = 1; i <= m; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         g[a].push_back({b, c});
//         g[b].push_back({a, c});
//     }
//     while (q--)
//     {
//         int start, end;
//         cin >> start >> end;
//         int value = dfs(start, end);
//         if (value == inf)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             cout << value << endl;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
int32_t main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dis(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = inf;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }

    for( int k=0 ;k< n ;k++){
        for( int i=0 ;i< n ;i++){
            for( int j=0 ;j<n  ;j++){
                dis[i][j] = min ( dis[i][k] + dis[k][j] , dis[i][j]);
            }
        }
    }

    while( q--){
        int a , b;
        cin>>a>>b;
        a-- ;
        b--;
        int ans= dis[a][b];
        if( ans == inf){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }

    }

    return 0;
}