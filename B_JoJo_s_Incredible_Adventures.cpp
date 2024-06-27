#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        s = s + s;
        int ans = 0;
        int current = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                current++;
            }
            else
            {
                current = 0;
            }
            ans = max(ans, current);
            
        }
        int n= s.length()/2;

        if( ans > n ){
            cout<< n*n <<endl;
        }else{
            int a  = (ans+1)/2;
            int b=  (ans+2)/2;
            cout<<a*b<<endl;
        }
    }
    return 0;
}