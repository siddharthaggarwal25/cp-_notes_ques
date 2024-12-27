#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, k;
        cin >> m >> k;
        vector<int> v(m);
        for (int i = 0; i < m; i++)  cin >> v[i];
        
        bool current ;
        for (int i = 0; i < m; i++)
        {
            current = true;
            for (int j = 0; j < m; j++)
            {
                if (i!= j  &&  (abs(v[i] - v[j]) % k) == 0)
                {
                    current = false;
                    break;
                }
            }

            if (current)
            {
                cout << "YES" << endl;
                cout << i+1 << endl;
                break ;
            }
        }

        if (!current)
            cout << "NO" << endl;
    }
    return 0;
}