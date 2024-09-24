#include <bits/stdc++.h>
using namespace std;
int f(int x)
{
    int cnt = 0;
    while (x)
    {
        x = x / 3;
        cnt++;
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    vector<int> req(2e5 + 5, 0);
    vector<int> arr(2e5 + 5, 0);
    for (int i = 1; i <= 2e5; i++)
    {
        int temp = f(i);
        arr[i] = temp;
        req[i] = req[i - 1] + temp;
    }
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int ans = arr[l] + req[r] - req[l - 1];
        cout << ans << endl;
    }
    return 0;
}