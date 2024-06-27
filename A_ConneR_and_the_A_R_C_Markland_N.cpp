#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        arr[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int element = n;
        for (int i = 1; i <= n; i++)
        {
            int *index = find(arr, arr + n, i);
            if (index == arr + n)
            {
                element = i;
                break;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int score = 0;
            for (int j = 1; j < <= n; j++)
            {
                score = score +
            }
        }
    }
    return 0;
}
