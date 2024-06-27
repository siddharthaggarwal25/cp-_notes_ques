#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 1];
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            if (i > 1)
            {
                arr[i] += arr[i - 1];
            }
        }
        bool check = true;
        int val = sum / n;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] < i * val)
            {
                check = false;
                break;
            }
        }
      
        if( check){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}