#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans =0 ;
        int val = 0 ;
        vector<vector<int>> v(n);
        int mini =1e9;
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                v[i].push_back(x);
            }
            sort( v[i].begin() , v[i].end());
            val += v[i][1];
            mini = min ( mini  , v[i][0]);
        }

        for( int i =0 ;i < n ;i++){
            ans  = max( ans  , val - v[i][1] +mini);
        }
        cout<<ans<<endl;
    }
    return 0;
}