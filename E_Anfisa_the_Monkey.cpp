#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, a, b;
    cin >> k >> a >> b;
    string s;
    cin >> s;
    int n = s.length();

    if (n - a * k < 0 || n - b * k > 0)
    {
        cout << "No solution" << endl;
    }
    else
    {
        int r;
        int l=0;
        for (; k > 0; k--)
        {
            r = (n - l) / k;
            cout << s.substr(l, r) << endl;
            l += r;
        }
    }

    return 0;
}