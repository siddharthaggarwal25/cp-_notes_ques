#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool ans = true;
        c -= a;
        d -= b;

        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);

        if ((ceil((b + a) / (a + 1))) >= 3)
            ans = false;
        if ((ceil((d + c) / (c + 1))) >= 3)
            ans = false;

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}