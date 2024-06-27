#include <bits/stdc++.h>
using namespace std;
#define int long long
// calcuate number of tailing zeros in n factorial,
int32_t main()
{
    int n;
    cin >> n;
    // number iof zeros - is eual to min 2 ,
    // 5 facor in thaht numberG
    int count = 0;

    int num = 5;
    while (num <= n)
    {
        int ans = n / num;
        count += ans;
        num = num * 5;
    }

    cout << count << endl;
    return 0;
}


// / numner of factiors in a favotrial vcna be calucyerd using  n / 5 ,.  n / 5*5 tyile 5*5 ,.. < n 