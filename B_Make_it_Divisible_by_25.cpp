#include <bits/stdc++.h>
#define int long long
using namespace std;

int number(int n, char a, char b)
{

    string s = to_string(n);
    int count = 0;
    int current =-1;
    for (int i = s.length() -1; i >=0 ; i--)
    {   
        count ++;
        if ( s[i] == b ){
            count--;
            current = i;
            break;
        }
    }
    
    if(current == -1){
        return 1e17;
    }
    int current2=-1 ;
    for(int i= current -1  ;i>=0 ;i-- ){
        count ++;
        if( s[i] == a){
            count --;
            current2 =i;
            break;
        }
    }
    if( current2 == -1){
        return  1e17;
    }

    return count ;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int value1 = number(n, '0', '0');
        int value2 = number(n, '5', '0');
        int value3 = number(n, '2', '5');
        int value4 = number(n, '7', '5');

        cout<< min( value1 , min( value2  , min( value3 ,value4)))<<endl;;
    }

    return 0;
}