#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int cnt =0 ;    
        int miniModulo = 1e9;
        for (int i = 0; i < n; i++)
        {

            int mini = v[i] % k;
            if (mini != 0)
                miniModulo = min(miniModulo, k - mini);
            else
                miniModulo = 0;

            if( v[i]%2 ==0)cnt ++;    
        }

        if (k == 4)
        {
             if( miniModulo == 0 || cnt >= 2)cout<<0<<endl;
             else if( miniModulo ==1 || cnt ==1 )cout<<1<<endl;
             else cout<<2<<endl;         
        }
        else
        {
            cout << miniModulo << endl;
        }
    }
    return 0;
}