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
        vector<int> v;
        v.push_back(-1e9);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (v.back() != x)
                v.push_back(x);
        }
        v.push_back(-1e9);
        int cnt = 0;

        for (int i = 1; i < v.size() -1; i++)
        {
            if (v[i] > v[i - 1] && v[i] > v[i + 1])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}