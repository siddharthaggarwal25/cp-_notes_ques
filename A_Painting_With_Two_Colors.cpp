#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (a >  b)
        {
            if (n % 2 == 1 && a % 2 == 1 && b % 2 == 1)
                cout << "YES" << endl;
            else if (n % 2 == 0 && a % 2 == 0 && b % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (n % 2 == 1 && b % 2 == 1)
                cout << "YES" << endl;
            else if (n % 2 == 0  && b % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

    }
    return 0;
}