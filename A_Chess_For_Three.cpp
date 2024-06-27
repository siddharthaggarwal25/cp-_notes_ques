#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
        int a , b , c ;
        cin>>a>>b>>c;
         int sum = a+b+c;
         if( sum%2 ==0 ){
            if( a+b <= c){
                cout<<a+b<<endl;
            }else{
                int  count =0 ;
                while( a+b>c  ){
                    count++;
                    a--;
                    b--;
                }
                cout<<count +a+b<<endl;
            }

         }else{
            cout<<-1<<endl;
         }
     }
return 0;
}