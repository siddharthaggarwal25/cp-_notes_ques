#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        vector<int> prefix(n);

        if( s[0] == 'L')prefix[0]= -1;
        else prefix [0] = +1;

        for( int i =1  ;i< n ;i++){
             if( s[i] =='L')prefix[i] = prefix[i-1] - 1;
             else prefix[i] = prefix[i-1] + 1; 
        }

        int toCheck  = 0 - x ;
        int count =0 ;
        for( int i =0  ;i< n ;i++ ){
            k--;
             if( prefix[i] == toCheck) {
                  if(  k >=0) count++;
                 break ; 
             }
        }

        if( count  >0 &&  k> 0){
             int temp = -1 ;
              for( int i =0  ;i< n ; i++){
                 if( prefix[i] == 0)  {
                    temp = i+1  ;
                     break ;
                 }
              }

              if( temp >0)  count  +=  k/temp ;
        }
        cout<<count<<endl; 
    }
    return 0;
}