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

        int q;
        cin >> q;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "->")
            {
                int x, y;
                cin >> x >> y;

                int size = pow(2, n);
                int val = 1;

                while (size > 1)
                {
                    int cur_size = (size * size) / 4;

                    if (x <= size / 2 && y <= size / 2)
                    {
                        val = val;
                    }
                    else if (x > size / 2 && y <= size / 2)
                    {
                        val += cur_size * 2;
                        x = x - size / 2;
                    }
                    else if (x <= size / 2 && y > size)
                    {
                        val += cur_size * 3;
                        y = y - size / 2;
                    }
                    else
                    {
                        val += cur_size;
                        x = x - size / 2;
                        y = y - size / 2;
                    }
                    size = size / 2;
                }
                cout << val << endl;
            }
            else
            {
                int d;
                cin >> d;

                int size = pow(2, n);
                int curx = 1;
                int cury = 1;

                while (size > 1)
                {
                    int cur_size = (size * size) / 4;

                    int start = 1;
                    int end = cur_size;
                    int i;
                    for (i = 1; i <= 4; i++)
                    {

                        if (d >= start && d <= end)
                        {
                            d = d - start + 1;
                            break;
                        }
                        else
                        {
                            start = end + 1;
                            end = end + cur_size;
                        }
                    }

                    if (i == 2)
                    {
                        curx += size / 2;
                        cury += size / 2;
                    }
                    else if (i == 3)
                    {
                        curx += size / 2;
                    }
                    else if (i == 4)
                    {
                        cury += size / 2;
                    }

                    size = size / 2;
                }

                cout << curx << " " << cury << endl;
            }
        }
    }
    return 0;
}