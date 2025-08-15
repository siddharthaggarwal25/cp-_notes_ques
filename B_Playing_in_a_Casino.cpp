#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{   
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[j][i];
            }
        }

        int ans =0 ;
        for( int i=0 ;i< m  ;i++){
             sort( v[i].begin() , v[i].end());
             vector<int > prefix( n);
             prefix[0] = v[i][0];
             for( int j=1 ;j<n ;j++){
                prefix [j] = prefix[j-1] + v[i][j];
             }

             for( int j= n-1  ;j>=1 ;j-- ){
                ans = ans  + ( v[i][j]*( j) -  prefix[j-1]);
             }
        }
        cout<<ans<<endl;

    }

    return 0;
}