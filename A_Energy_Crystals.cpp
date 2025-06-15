#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
         int n ;
          cin>>n ;
          //  1 1 0 
          int cnt  =2 ;
          int temp  = 1  ;

          while( temp < n){
             temp = ( temp*2 +1);
             cnt  += 2 ;
          }
          cout<< cnt+1<<endl;
    }
    return 0;
}