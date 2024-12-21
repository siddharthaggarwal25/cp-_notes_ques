    #include <bits/stdc++.h>
    using namespace std;
    #define int long long 
    int32_t main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int a, b;
            cin >> a >> b;
            b = b - a;
            a = 0;
            int low = 1;
            int high = b;
            int ans = 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int val = (mid) * (mid + 1) / 2;

                if (val <= b)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if( b == 0 ) ans  =0 ;
            cout << ans+1 << endl;
        }
        return 0;
    }