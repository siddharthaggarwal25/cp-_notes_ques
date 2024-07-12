#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        vector<int> arr(k);
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        sort( arr.begin() , arr.end());
        for( int i=0 ;i< k-1 ;i++){
            cnt  = cnt  + arr[i] -1  + arr[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}