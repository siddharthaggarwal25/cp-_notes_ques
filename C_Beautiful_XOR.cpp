#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        

        int lastind = 0;

        for (int i = 0; i < 32; i++)
        {
            if (a & (1 << i))
                lastind = i;
        }

        int num = 0;
        int temp1 = 0;
        for (int i = 0; i <= lastind; i++)
        {
            num = num |( 1 << i);

            if (a & (1 << i))
                temp1 = temp1;
            else
                temp1 = temp1 |( 1 << i);
        }

        if (num < b)
        {
            cout << -1 << endl;
        }
        else
        {
           int  temp = 0;
            for (int i = 0; i <= lastind; i++)
            {
                if (b & (1 << i))
                {
                    continue;
                }
                else
                {
                    temp = temp | (1 << i);
                }
            }
         

            cout << 2 << endl;
            cout << temp1 << " " << temp << endl;
        }
    }
    return 0;
}