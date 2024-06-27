#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, f, a, b;
        cin >> n >> f >> a >> b;
        int arr[n +1 ];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int count = 0;
        int var =0 ; 

        for (int i = 1; i <= n; i++)
        {
            f = f- min( b , (abs(arr[i] - var ))*a);
            var = arr[i];

        }
        
        if (f>0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}