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
        int mini =0, maxi=0;
    
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> B[i];
        for (int i = 0; i < n; i++)
        {  
            int temp = maxi ;
            maxi = max(maxi - A[i], B[i] - mini);
            mini = min(mini - A[i], B[i] - temp);
        }
        cout << maxi << "\n";
    }
    return 0;
}