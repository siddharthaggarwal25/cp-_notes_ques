#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if (x1 == x2)
        {
            cout << (abs(y1 - y2) * abs(x1 - x3))<<endl;
        }
        else if (x1 == x3)
        {
            cout << (abs(y1 - y3) * abs(x1 - x2))<<endl;;
        }
        else
        {
            cout << (abs(y1 - y4) * abs(x1 - x2))<<endl;;
        }
    }
    return 0;
}