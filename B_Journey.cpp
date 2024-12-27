#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int q = a + b + c;
        int days = 3 * (n / q);
        n = n % q;

        if (n == 0);
        else if (n <= a)  days++;
        else if (n <= a + b)days += 2;
        else  days += 3;

        cout<<days<<endl;
    }
    return 0;
}