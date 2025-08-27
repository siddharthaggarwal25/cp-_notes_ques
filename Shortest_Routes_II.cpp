
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