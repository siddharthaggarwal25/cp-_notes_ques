// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     int n = s.length();
//     vector<int> arr(26, 0);

//     for (int i = 0; i < n; i++)
//     {

//         cout << arr[i] << " ";
//         arr[s[i] - 'A']++;

//     }

//     int count = 0;
//     int address = -1;
//     for (int i = 0; i < 26; i++)
//     {
//         if ((arr[i] % 2) == 1)
//         {
//             count++;
//             address = i;
//         }
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     if (count > 1)
//     {
//         cout << "NO SOLUTION" << endl;
//     }
//     else

//     {
//         int value = -1;
//         if (address != -1)
//         {
//             arr[address] = 0;
//         }
//         for (int i = 0; i < 26; i++)
//         {
//             for (int j = 0; j < arr[i] / 2; i++)
//             {
//                 cout << char(i + 'A');
//             }
//         }
//         if (count == 1)
//         {
//             for (int i = 0; i < value; i++)
//             {
//                 cout << char('A' + address);
//             }
//         }

//         for (int i = 25; i >= 0; i++)
//         {
//             for (int j = 0; j < arr[i] / 2; i++)
//             {
//                 cout << char(i + 'A');
//             }
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v(26, 0);

    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'A']++;
    }
    int count = 0;
    int address = -1;
    for (int i = 0; i < 26; i++)
    {
        if ((v[i] % 2) == 1)
        {
            count++;
            address = i;
        }
    }

    // cout << count << " " << address;

    if (count > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else

    {
        int value = -1;
        if (address != -1)
        {
            value = v[address];
            v[address] = 0;
        }
        // cout<<address;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < (v[i] / 2); j++)
            {
               cout << char(i + 'A');
            }
        }
        if (count == 1)
        {
            for (int i = 0; i < value; i++)
            {
                cout << char('A' + address);
            }
        }

        for (int i = 25; i >= 0; i--)
        {
            for (int j = 0; j < (v[i] / 2); j++)
            {
                cout << char(i + 'A');
            }
        }
    }

    return 0;
}