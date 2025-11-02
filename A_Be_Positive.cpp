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
        int zeros = 0;
        int minus = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
                zeros++;
            else if (x == -1)
                minus++;
        }

        cout << ((minus % 2)*2 + zeros) << endl;
    }
    return 0;
}