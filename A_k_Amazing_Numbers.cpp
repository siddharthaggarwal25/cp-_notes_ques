#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> ans(n+1, -1);
        map<int , vector<int >> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]].push_back( i);
        }

        for( auto it  : mp){
             auto &v =it.second ;

             v.insert( v.begin() , -1);
             v.push_back( n);
             int maxgap =0;
             for( int  i=1  ;i< v.size() ;i++){
                 maxgap = max( maxgap , v[i] - v[i-1]);
             }

             for( int i= maxgap ;i<=n && ans[i]== -1  ;i++){
                ans[i] = it.first;
             }
        }

        for( int i=1 ; i<= n  ;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}