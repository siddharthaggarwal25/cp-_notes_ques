#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n + 1; i++)
            cin >> b[i];
        int t = b[n];
        bool flag = false;
        int sum = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= b[i])
            {
                if (a[i] >= t && t >= b[i])
                {
                    flag = true;
                    // cout<<"qefqw";
                }
                sum += abs(a[i] - b[i]);
            }
            else
            {
                if (a[i] <= t && t <= b[i])
                {
                    // cout<<"qefqw";
                    flag = true;
                }
                sum += abs(a[i] - b[i]);
            }
        }
        if( flag ){
            cout<<sum<<endl;
        }else{
             int diff = INT_MAX;
             for( int i  = 0;i< n   ;i++){
                diff = min ( diff  , abs( t - a[i]));
             }
             for( int i  = 0;i< n   ;i++){
                diff = min ( diff  , abs( t - b[i]));
             }
             sum+= diff;
             cout<<sum<<endl;
        }
    }
    return 0;
}