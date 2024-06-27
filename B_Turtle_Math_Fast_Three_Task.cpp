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
        int arr[n];
        int sum = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] = arr[i] % 3;
            sum += arr[i];
            mp[arr[i]]++;
        }

        sum = sum % 3;
        if (sum == 0)
        {
            cout << 0 << endl;
        }
        else if (sum == 1)
        {
            if (mp[sum] != 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}