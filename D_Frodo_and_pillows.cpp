#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    m= m-n ;
    int a=1 ;
    int c=1 ; 

    while(m>0 ){
        if( k + a <= n ) c++;
        if( k-a >= 1) c++;
        m = m- c;
        a++;
    }
    cout<<a<<endl;
    return 0;
}