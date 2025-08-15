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

        int incStarts = 0, decStarts = 0;
        int trend = -1;

        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
                continue;

            if (v[i] > v[i - 1])
            {
                if (trend != 1)
                {
                    // cout<<i <<" ?";
                    incStarts++;
                    trend = 1;
                }
            }
            else
            {
                if (trend != 0)
                {  
                    // cout<<i<<" /";
                    decStarts++;
                    trend = 0;
                }
            }
        }

        cout <<  incStarts + 1 + decStarts << endl;
    }
    return 0;
}
