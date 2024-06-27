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
        int arr[n];
        int sum =0 ;
        for (int i = 0; i < n; i++)
        { 
            
            cin >> arr[i];
            sum += arr[i];
        }
        if( sum <= k){
            cout<<n<<endl;
            continue;
        }
        int first = k / 2;
        int last = k / 2;
        if (k % 2 == 1)
            first++;
        int p1[n], p2[n];
        p1[0] = arr[0];
        p2[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            p1[i] = p1[i - 1] + arr[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            p2[i] = p2[i + 1] + arr[i];
        }

        reverse(p2, p2 + n);
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (p1[i] <= first)
                count1++;
            else
                break;
        }
        for (int i = 0; i < n; i++)
        {
            if (p2[i] <= last)
                count2++;
            else
                break;
        }
        cout <<  count1 + count2<< endl;
    }
    return 0;
}