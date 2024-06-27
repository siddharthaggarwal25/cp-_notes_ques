#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;

    arr.push_back(0);
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
     
     int flag =0 ;
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] != i)
        {   flag =1;
            cout << i << endl;
            break;
        }
    }
    if( flag == 0){
        cout<<n<<endl;
    }

    return 0;
}