#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> list(m), v(n + 1);
        for (int i = 0; i < m; i++)
            cin >> list[i];

        int sum = n - k;
        int a;
        for (int i = 1; i <= n; i++)
            v[i] = 1;
        for (int i = 0 ;  i < k; i++)
        {
            cin >> a;
            v[a] = 0;
        }

        string ans  = "";
        for( int i =0  ; i < m  ;i++){
            if( sum  ==0  || ( sum==1 && v[list[i] ] == 1)  ) ans +="1";
            else  ans  +="0";
            
        }
        cout<<ans<<endl;
    }
    return 0;
}