
#include <bits/stdc++.h>
using namespace std;

int sumDigitSquare(int n)
{
    int sq = 0;
    while (n) {
        int digit = n % 10;
        sq += digit * digit;
        n = n / 10;
    }
    return sq;
}

bool isHappy(int n)
{

    set<int> s;
    s.insert(n);
    while (1) {
        if (n == 1)
            return true;

        n = sumDigitSquare(n);
        if (s.find(n) != s.end())
        s.insert(n);
    }

    return false;
}

int main()
{
     int n ;
     cin>>n;
    if (isHappy(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
