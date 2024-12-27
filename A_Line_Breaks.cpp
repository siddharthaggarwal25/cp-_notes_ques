#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >>n >> m;
        vector<string> v(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i =0 ; i< n  ;i++){
            if( m >= v[i].length()) {
                ans ++;
                m -= v[i].length();
            }else{
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}