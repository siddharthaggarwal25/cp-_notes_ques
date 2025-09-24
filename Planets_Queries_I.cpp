#include <bits/stdc++.h>
using namespace std;
#define int long long
int succesor[200002][33];
int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    int x, k;

    cin >> n >> q;
    // succesor.resize(n + 1, vector<int>(33));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        succesor[i][0] = a;
    }

    for (int i = 1; i < 33; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int halfsuccesor = succesor[j][i - 1];
            succesor[j][i] = succesor[halfsuccesor][i - 1];
        }
    }

    while (q--)
    {
        cin >> x >> k;
        for (int i = 32; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                x = succesor[x][i];
            }
        }

        cout << x << "\n";
    }

    return 0;
}