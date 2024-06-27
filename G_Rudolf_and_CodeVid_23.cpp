#include <bits/stdc++.h>
using namespace std;
int binaryToDecimal(string str)
{
    int sz = str.size();
    reverse(str.begin(), str.end());
    int ans = 0;
    for (int i = 0; i < sz; i++)
    {
        if (str[i] == '1')
        {
            ans += (1 << i);
        }
    }
    return ans;
}
int main()
{
    int bad = 23;
    int good = 16;
    int fin = 0;
    for (int j = 0; j < 11; j++)
    {
        if (bad & (1 << j))
        {
            if (!(good & (1 << j))){
                fin =  fin  + (1<<j);
            }
        }

     
    }
    // cout<<fin<<endl;
    return 0;
}