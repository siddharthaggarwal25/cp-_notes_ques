#include <bits/stdc++.h>
using namespace std;
#define int long long 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int oddCount[n] = {0};
        if (arr[0] % 2 == 0)
        {
            oddCount[0] = 0;
        }
        else
        {
            oddCount[0] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                oddCount[i] += 1;
            }
            oddCount[i] += oddCount[i - 1];
        }

        int prefix[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        cout << arr[0] << " ";

        for (int i = 1; i < n; i++)
        {
          if( oddCount[i]%3 == 1){
            cout<< prefix[i] - oddCount[i]/3 -1<<" ";
          }else{
            cout<<prefix[i] - oddCount[i]/3<<" ";
          }

        }
        cout << endl;
    }
    return 0;
}