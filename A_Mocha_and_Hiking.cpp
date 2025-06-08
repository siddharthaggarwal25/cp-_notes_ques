#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
       cin>>t ;
        while( t--){
             int n ;
              cin>>n  ;
               vector<int > v( n+1);
                for( int i = 1;i<= n  ;i++)cin>>v[i];

                if( v[1] == 1){
                      cout<<n+1<<" ";
                      for( int  i= 1 ;i<=n  ;i++)cout<<i<<" ";
                }
                else if( v[n] == 0){
                    for( int i=1  ;i<= n+1  ;i++)cout<<i<<" ";
                }else{
                     int ind  =-1 ;
                     for( int i = 1  ;i<= n-1 ;i++){
                         if( v[i] == 0 && v[i+1] ==1){
                             ind  = i ;
                             break ;
                         }
                     }

                     if( ind  == -1)cout<<-1;
                     else{
                         for( int i= 1 ;i<= n ;i++){
                            cout<<i<<" ";
                            if( i== ind)cout<<n+1<<" ";
                         }
                     }
                }
                cout<<endl;
        }
return 0;
}