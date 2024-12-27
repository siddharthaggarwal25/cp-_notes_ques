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
        long long int sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        int a = 0;
        int b = 0;
        int c  = sum/n ;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                a += c - v[i];
            else
                b += c - v[i];
        }

        if (a == 0 && b == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}