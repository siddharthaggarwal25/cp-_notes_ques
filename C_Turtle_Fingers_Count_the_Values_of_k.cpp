#include <bits/stdc++.h>
using namespace std;
#define int long long

int  power(int A, int  B)
{
    if (B == 0)
        return 1;
 
    int  res = power(A, B / 2);
 
    if (B % 2)
        return res * res * A;
    else
        return res * res;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        int x=0 ;
        int y=0 ;
        set<int > s;
        for( int i=0 ;i<=20 ;i++){
            for( int j=0 ;j<= 20;j++){
                int value = power( a,i)*power(b, j);
                if( l%value  == 0){
                    s.insert( value );
                    continue;
                }
                break;
            }
        }
        cout<<s.size()<<endl;
 
        
    }
    return 0;
}