#include <bits/stdc++.h>
using namespace std;
#define int long long
int modulo = 1e9 + 7;

int32_t main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'w' || s[i] == 'm')
        {
            cout << 0 << endl;
            return 0;
        }
    }

    int dp[s.length()+1];
    dp[0]=1;
    dp[1]=1;

    for(int i=2 ;i<=s.length() ;i++){
        if( s[i-1] ==s[i-2] && (s[i-1]=='u' || s[i-1] == 'n' )){
            dp[i] =( dp[i-1] + dp[i-2])%modulo;
        }else{
            dp[i]=dp[i-1];
        }
    }
    cout<<dp[s.length()]<<endl;

    return 0;
}