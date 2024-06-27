#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int ans = sum;
    int ind = 0;
    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        if (sum < ans)
        {
            ind  = i-k +1  ;
            ans = sum ;
        }
    }
    cout << ind + 1 << endl;
    return 0;
}