#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isFair(int n){
     int temp =n ;
     while( temp>0){
         int last = temp%10 ;
          temp = temp/10 ;
          if( last != 0 && n%last!= 0 )return false;
     }
     return true ;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for( int i=0 ;i<=2520 ;i++){
             if( isFair( n)){
                cout<<n<<endl;
                break ;
             }else{
                n++;
             }
        } 
    }
    return 0;
}
