#include <bits/stdc++.h>
using namespace std;
#define int long long
int m = 1e9 + 7;

int binaryExponentation(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return (binaryExponentation(((x % m) * (x % m)) % m, n / 2)) % m;

    return ((x % m) * binaryExponentation(((x % m) * (x % m)) % m, n / 2)) % m;
}
int32_t main()
{
    int n;
    cin >> n;
    int ans = 1;
    cout << binaryExponentation(2, n) << endl;

    return 0;
}