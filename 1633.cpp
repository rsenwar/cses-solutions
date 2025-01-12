#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n+1]={0};
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    int mod=1e9+7;
    for(int i=3;i<=n;i++) {
        for(int j=i-1;j>=max(0,i-6);j--) {
            arr[i] = (arr[i]+arr[j])%mod;
        }
    }
    
    cout<<arr[n];
}

