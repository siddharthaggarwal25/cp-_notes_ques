#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n , m , k ;
        cin>>n>>m>>k;
        int a[n] , b[m];
        for(int i=0 ;i< n ;i++){
            cin>>a[i];
        }
        for(int j=0 ;j< m ;j++){
            cin>>b[j];
        }
        sort(a , a+n );
        sort( b , b+ m);

        int flag1[k+1] , flag2[k+1];
        memset( flag1 , 0  ,  sizeof(flag1));
        memset( flag2 , 0  ,  sizeof(flag2));

        for(int i=0 ;i<n ;i++){
            if( a[i] > k ){
                break;
            }else{
                flag1[a[i]] =1;
            }
        }

        for(int i=0 ;i<m ;i++){
            if( b[i] > k ){
                break;
            }else{
                flag2[b[i]] =1;
            }
        }
        int count =0 ;
        int countFlag1=0;
        int countFlag2=0;
        bool ans = true;

        for(int i=1 ;i<= k ;i++){
            if( flag1[i] == 0 && flag2[i]==0){
                ans = false;
                break;
            }
            if( flag1[i] == 1 && flag2[i]==0){
                countFlag1++;
            }
            if( flag1[i] == 0 && flag2[i]==1){
                countFlag2++;
            }
            if( flag1[i] == 1 && flag2[i]==1){
                count ++;
            }
        }

        if(  ( countFlag1 > k/2)  || (countFlag2>k/2) ){
            ans = false;
        }

        if( ans ){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }



     
     }
return 0;
}