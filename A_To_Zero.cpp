#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int count = 0;
        int odd_k = k, even_k = k;
        if (k % 2 == 0)
            odd_k--;
        else
            even_k--;

        if (n % 2 == 0)
        {
             if(  n% even_k == 0 )cout<<n/even_k<<endl;
             else cout <<n/even_k +1 <<endl;
        }
        else
        {    n = n- odd_k;

            if(  n% even_k == 0 )cout<< 1+ n/even_k<<endl;
            else cout <<n/even_k +2<<endl;
        }
    }
    return 0;
}