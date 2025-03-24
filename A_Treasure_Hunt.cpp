#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, a;
        cin >> x >> y >> a;
        a = a % (x + y);

        a = a - x;
        if (a < 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}