#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int price[n];
for(int i=0 ;i<n ;i++){
    cin>>price[i];
}
// price[n]=INT_MAX;
int q;
cin>>q;
int amount[q];
for(int i=0 ;i<q ;i++){
    cin>>amount[i];
}

sort(price ,price+n);

int ans =0 ;
for(int i=0 ;i<q ;i++){

    int ans = upper_bound(price ,price+n , amount[i]) - price;
    cout<<ans<<endl;
}


    return 0;
}
