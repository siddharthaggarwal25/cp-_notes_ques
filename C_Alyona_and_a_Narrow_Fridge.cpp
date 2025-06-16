#include <bits/stdc++.h>
using namespace std;
#define int long long

class  temp {
    public :
     int a  = 1 ;

     void p ( ){
        cout<<a<<endl;
     }
     void ( int x){
        a = x 
     }
     
};
temp sid ; 
int check(vector<int> &bottles, int ind)
{ 
    vector<int> temp = bottles;
    sort(temp.begin() + 1, temp.begin() + ind + 1, greater<int>());
    int height = 0;
    for (int i = 1; i <= ind; i += 2)
    {
        if (i + 1 <= ind)
            height += max(temp[i], temp[i + 1]);
        else
            height += temp[i];
    }
    return height;
}
int32_t main()
{
    // int n, h;
    // cin >> n >> h;
    // vector<int> bottles(n + 1 , 0 );
    // for (int i = 1; i <= n; i++)cin >> bottles[i];

    // int low = 1;
    // int high = n;
    // int ans  =1  ;
    // while (low <= high)
    // {
    //     int mid = (low )  +( high -low )/ 2;

    //     if (check(bottles, mid) <= h)
    //     {
    //         low = mid + 1;
    //         ans = mid;
    //     }
    //     else
    //     {
    //         high = mid - 1;
    //     }
    // }
    // cout << ans  << endl;
    sid.p();

    return 0;
}