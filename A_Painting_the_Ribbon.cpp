    #include<bits/stdc++.h>
    using namespace std;
    int  main (){
        int t;
        cin>>t;
        while( t--){
            int n , m   ,k ;
            cin>>n>>m>>k ;
            int j= 1 ;
            vector< int > v ( n+1);
            for(int i=1 ;i <= n ;i++){
                v[i] = j;
                j++ ;
                if( j>m ) j=1 ;

            }
            vector< int> freq( n+1 , 0 );
            for( int i=1 ;i<= n  ;i++){
                freq[v[i]]++;
            }
            sort( freq.begin() +1  , freq.end() );
            
            int ans =0 ;
            for( int i=1 ;i <n ;i++) {
                ans  += freq[i];
            }
            if( ans <= k){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }

        
        }
    return 0;
    }