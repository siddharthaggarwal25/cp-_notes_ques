#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 6;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (j - i <n / 2)
            cout << i + 1 << " " << j + 1 << "->  " << 1 << endl;
            else if (j - i == n / 2)
            // cout << 0 << " ";
            cout << i + 1 << " " << j + 1 << "->  " << 0 << endl;
            else

                cout << i + 1 << " " << j + 1 << "-> " << -1 << endl;
    cout << endl;
    return 0;
}