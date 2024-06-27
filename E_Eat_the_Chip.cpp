#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> ya >> xa >> yb >> xb;

        int diff = yb - ya;

        if (diff < 0)
        {
            cout << "Draw" << endl;
            continue;
        }
      

        if (diff % 2 == 0)
        {
            // bob wins
            int steps = diff / 2;
            if (xa > xb)
            {
                xa = min(w, xa + steps);
                if (xa <= (xb + steps))
                {
                    cout << "Bob" << endl;
                }
                else
                {
                    cout << "Draw" << endl;
                }
            }
            else
            {

                xa = max(1ll, xa - steps);
                if (xa >= (xb - steps))
                {
                    cout << "Bob" << endl;
                }
                else
                {
                    cout << "Draw" << endl;
                }
            }
        }
        else
        {
            // alice  wins

            int steps = diff / 2 + 1;
            int step2 = diff / 2;
            if (xb > xa)
            {
                xb = min(w, xb + step2);
                if (xa + steps >= xb)
                {
                    cout << "Alice\n";
                }
                else
                {
                    cout << "Draw\n";
                }
            }
            else
            {
                xb = max(1ll, xb - step2);
                if (xa - steps <= xb)
                {
                    cout << "Alice\n";
                }
                else
                {
                    cout << "Draw\n";
                }
            }
        }
    }

    return 0;
}