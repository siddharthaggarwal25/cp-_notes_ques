#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n - 1 > k)
        {
            cout << n << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}