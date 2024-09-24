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
        int maxi = 0;
        while (n--)
        {
            int l;
            cin >> l;
            map<int, int> mp;
            for (int i = 0; i < l; i++)
            {
                int x;
                cin >> x;
                mp[x]++;
            }
            int cur = 0;
            int cnt = 0;
            while (1)
            {
                if (mp[cur] == 0)
                {
                    maxi = max(maxi, cur);
                    cnt++;
                }
                cur++;
                if (cnt == 2)
                    break;
            }
        }
        if( maxi >= m ){
            cout<<maxi*( m+1)<<endl;
        }else{
            cout<< maxi*maxi + ( m + maxi )*( m-maxi +1)/2<<endl;;
        }
    }
    return 0;
}