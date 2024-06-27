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
        vector<int> v(n + 1);
        vector<int> close(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        close[1] = 2;
        close[n] = n - 1;
        for (int i = 2; i < n; i++)
        {

            if ((v[i] - v[i - 1]) < (v[i + 1] - v[i]))
            {
                close[i] = i - 1;
            }
            else
            {
                close[i] = i + 1;
            }
        }

        vector<int> frontAns(n + 1, 0);
        vector<int> backAns(n + 1, 0);
        frontAns[1] = 0;
        backAns[n] = 0;

        for (int i = 1; i < n; i++)
        {
            if (i + 1 == close[i])
            {
                frontAns[i + 1] = frontAns[i] + 1;
            }
            else
            {

                frontAns[i + 1] = frontAns[i] + v[i + 1] - v[i];
            }
        }

        for (int i = n; i > 0; i--)
        {
            if (close[i] == (i - 1))
            {
                backAns[i - 1] = backAns[i] + 1;
            }
            else
            {
                backAns[i - 1] = backAns[i] + v[i] - v[i - 1];
            }
        }

        int m;
        cin>>m;
        for(int i=0 ;i< m ;i++){

            int x ,y;
            cin>>x>>y;

            if( x<y){
                cout<< frontAns[y] - frontAns[x]<<endl;
            }else{

                cout<< abs(backAns[x]-  backAns[y])<<endl;
            }
        }
    }
    return 0;
}