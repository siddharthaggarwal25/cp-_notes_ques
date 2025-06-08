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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        v.push_back(-1e9);
        int ind = 1;
        int height = 0;
        int x = 1;
        while (true)
        {
            int cnt = 0;
            for (int i = 0; i < x; i++)
            {
                for (; ind < n; ind++)
                {
                    if (v[ind] < v[ind + 1])
                    {
                        cnt++;
                    }
                    else
                    {
                        cnt++;
                        break;
                    }
                }
            }
            x = cnt;
            height++;
            if (ind >= n)
                break;
        }
        cout << height << endl;
    }
    return 0;
}