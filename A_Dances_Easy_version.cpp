#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n], arr2[n];
        arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        sort(arr, arr + n);
        sort(arr2, arr2 + n);
        int index = 0;
        int count =0 ;
        for (int i = 0; i < n; i++)
        {
            index = upper_bound(arr2 + index, arr2 + n, arr[i]) - arr2;

            if(index == n ){
                break; 
            }
            count ++ ;
            index++ ;
        }
        cout<< n -count<<endl;

    }
    return 0;
}