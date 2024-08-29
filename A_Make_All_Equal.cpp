#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> freq(101, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        int maxi = 0;
        for (int i = 0; i < 101; i++)
        {
            maxi = max(maxi, freq[i]);
        }
        cout << n - maxi << endl;
    }
    return 0;
}