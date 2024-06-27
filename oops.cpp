#include <bits/stdc++.h>
using namespace std;
class counting
{
private:
    int val;
    static int count;

public:
    void setdata(int a)
    {
        val = a;
    }
    int getdata()
    {
        // cout<<count<<endl;
        return val;
    }
    static void setCount(){

    }
};

int main()
{
    counting sid;
    sid.setdata(1);
    cout<<sid.getdata()<<endl;

    return 0;
}