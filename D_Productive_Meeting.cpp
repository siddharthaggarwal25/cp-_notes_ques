#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
      cin>>t ;
      while( t--){
            int n ;
            cin>>n ;
            priority_queue<pair<int , int > > pq ;
            for( int i=1 ;i<=n  ;i++  ){
                 int a ;
                 cin>>a ;
                 if( a != 0 ) pq.push( { a , i});
            }

            vector<pair<int , int > > ans ;

            while( pq.size() >1 ){
                    pair<int , int > a = pq.top();
                    pq.pop();
                    pair<int , int > b = pq.top();
                    pq.pop();
                    ans.push_back ( { a.second  , b.second});
                    a.first--;
                    b.first--;
                   if( a.first > 0)pq.push( a);
                   if( b.first  > 0  )pq.push( b ); 
            }


            cout<<ans.size()<<endl;
            for(  auto it : ans ){
                cout<<it.first<<" "<<it.second<<endl;
            }
      }
return 0;
}