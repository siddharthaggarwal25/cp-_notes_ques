#include<bits/stdc++.h>
using namespace std;
 
int minStokes(vector<int> &arr, int s ,int e){
    if(s > e){
        return 0;
    }
    if(s == e){
        return min(arr[s], 1);
    }
    int minE = INT_MAX;
    int minIdx = -1;
    for(int i = s; i <= e; i++){
        if(minE > arr[i]){
            minE = arr[i];
            minIdx = i;
        }
    }
    for(int i = s; i <= e; i++){
        arr[i] -= minE;
    }
    int left = minStokes(arr, s, minIdx - 1);
    int right = minStokes(arr, minIdx + 1 , e);
    
    return min(e - s + 1, minE + left + right);
}
 
int main() {
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<minStokes(arr, 0, n - 1);
    return 0;
}