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
        int i = 1;
        while (1)
        {
            int cur = n / 2;
            
            if (n % 2 == 1)
            {
                cur++;
            }

            if (cur >= k)
            {
                cout << (2 * k - 1) * i << endl;
                break;
            }
            else
            {
                k = k - cur;
                i = i * 2;
                n = n / 2;
            }
        }
    }
    return 0;
}