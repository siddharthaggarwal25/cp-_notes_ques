#include <bits/stdc++.h>
using namespace std;
int32_t  main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n)  ,ans( n)  , used( n+1);

        for (int i = 0; i < n; i++) cin >> v[i];


        for( int i=0 ;i<n  ;i++){
            if( used[v[i]] == 0 ){
                ans[i] = v[i];
                used[v[i]] = 1;
            }
        }

        queue<int > q  ;
        for( int i=1  ;i<=n  ;i++){
            if( used[i] == 0){
                q.push( i);
            }
        }

        for( int i=0 ;i< n  ;i++){
            if( ans[i] ==0 ){
                ans[i] = q.front() ;
                q.pop();
            }
        }

        for( int i=0 ;i< n  ;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

       
    }
    return 0;
}