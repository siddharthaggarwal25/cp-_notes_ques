#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v(1e5 + 1);
    v[1] = 1;
    v[2] = 2;
    int last = 2;
    for (int i = 3; i <= 1e5; i++)
    {
        if (i == (2 * (last) + 1))
        {
            last = i;
            v[i] = v[i - 1] + 1;
        }
        else
        {
            v[i] = v[i - 1];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n] << endl;
    }
    return 0;
}