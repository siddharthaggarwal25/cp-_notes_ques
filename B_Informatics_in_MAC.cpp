#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int max =-1 ; 
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if( arr[i ] > max){
                max= arr[i];
            }
        }
        set<int> s1;
        set<int> s2;
        int index = -1;
        for (int i = 0; i < n; i++)
        {      
            s1.insert(arr[i]);
            if (s1.size() != (i + 1))
               {
                index = i;
                break;
            }
        }

        if (index == -1 )
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = index; i < n; i++)
        {
            s2.insert(arr[i]);
        }
        bool check =true;
        for (int i = 0; i <= max ; i++)
        {
            auto p1 = s1.find(i);
            auto p2 = s2.find(i);

            if (p1 == s1.end() && p2 == s2.end())
            {
                break;
            }
            
            if ((p1 == s1.end() && p2 != s2.end() )|| (p1 != s1.end() && p2 == s2.end()))
            {
                check = false;
                break;
            }
        }

        if( check){
            cout<< 2<<endl;
            cout<< 1 <<" "<< index  <<endl;
            cout<<index+1 << " "<< n <<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}