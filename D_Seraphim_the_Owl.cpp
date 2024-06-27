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
        int a[n+1];
        int b[n+1];
        for( int i=1  ;i<= n ;i++){
            cin>>a[i];
        } 
        for( int i=1  ;i<= n ;i++){
            cin>>b[i];
        } 
        int ans =0 ;
        for( int i=m+1  ;i<=n  ;i++){
            ans += min( a[i] , b[i]);
        }
        vector<int> v ;
        v.push_back( a[m]);
        int var =b[m] ;
        for( int i=m-1  ;i>0 ;i--){
           v.push_back( var + a[i] );
           var +=b[i];
        }
        int minm = *min_element(v.begin() ,  v.end() );
        ans+=minm;
        cout<<ans<<endl;
        // for( int i=0 ;i< v.size() ;i++){
        //     cout<<v[i]<<" ";
        // }

    }
    return 0;
}