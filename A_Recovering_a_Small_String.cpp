#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        n = n-3;
        int count = n/25;
        if( count ==0){
            cout<<"aa"<< char('a'+ n) <<endl;

        }else if (count ==1){
            cout<< 'a'<< char('a' + n-25)<<'z'<<endl;

        }else if(count ==2){
            cout<< char( 'a' + n-50)<<"zz"<<endl;

        }else{
            cout<<"zzz"<<endl;
        }
    }
    return 0;
}
