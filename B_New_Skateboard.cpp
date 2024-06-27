#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    string s;
    cin >> s;
    int count = 0;
    for(int i=0 ;i< s.length() ;i++){
        if( (s[i]-'0')%4 ==0){
            count++;
        }
    }
    for (int i = 0; i < s.length()-1; i++)
    {
        int num = (s[i]-'0')*10 + (s[i+1]-'0');
        if( num%4 ==0 ){
            count += i +1;
        }
        
    }
        cout<<count<<endl;
    return 0;
}