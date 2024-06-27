#include <bits/stdc++.h>
using namespace std;

int check(int num){
    int ans =0;
    while(num){
        ans = ans + num%10;
        num = num/10;
    }
    return ans;

}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n)
    {
        ans++;
        if( check(ans)== 10 ){
            n--;
        }
    }
 cout<<ans<<endl;

    return 0;
}