#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod = 998244353;
vector <int >v  ;

void factorial ( int maxi ){
     v.resize( maxi , 1 );
     for( int i= 1  ;i<maxi ;i++){
        v[i] = v[i-1]*i%mod;
     }
}

int32_t main()
{
    int t;
    cin >> t;
    factorial( 200002);
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        int l = 0;
        int r = 0;
        int cnt = 0;
        int ways = 1;
        while (r < n)
        {
            while (r <n && s[l] == s[r])
                r++;
            cnt++;
            ways = ways * (r - l ) % mod;
            l = r;
        }

        int op = n - cnt;
        ways = ways * v[n - cnt] % mod;
        cout << op << " " << ways << endl;
    }
    return 0;
}