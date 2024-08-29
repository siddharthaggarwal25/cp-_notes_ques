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
        vector<vector<int>> adj(n + 1);
        map<pair<int , int > , int   > mp;
        for (int i = 2; i <= n; i++)
        {
            int low = 1;
            int high = i;
            while (low < high)
            {
                if( mp[{low , high} ] != 0 )break ; 
               cout<<"?" <<" " <<low <<" "<<high<<endl;
               cout<<flush;
               int mid   ;
               cin>>mid  ;
                if( low == mid) {
                    adj[low].push_back( high);
                    mp[{ low  , high} ] == 1;
                     break  ; 
                }else {
                    low = mid  ;
                }
            }
        }
        cout<<"! ";
        for( int i=1 ;i<=n  ; i++){
          for( auto j : adj[i])     cout<<i <<" "<<j<<" " ;
          cout.flush();
        }
        cout<<endl;
        cout.flush();

    }

    return 0;
}