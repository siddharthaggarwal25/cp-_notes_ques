#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + 1 != c)
        {
            cout << -1 << endl;
        }
        else
        {
            queue<int> s;
            for (int i = 0; i < c; i++)
            {
                s.push(0);
            }
            for (int i = 0; i < b; i++)
            {
                int val =s.front();
                s.pop();
                s.push(val+1);
            }
            for (int i = 0; i < a; i++)
            {
                s.pop();
                int val = s.front();
                s.pop();
                s.push(val+1);
            }
            cout<<s.front()<<endl;
        }
    }
    return 0;
}