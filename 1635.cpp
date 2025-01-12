#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x, mod = 1e9+7;
    cin>>n>>x;
    vector<int> c;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        c.push_back(num);
    }
    vector<int>dp(x+1, 0);
    dp[0] = 1;
    for(int i=1;i<=x;i++) {
        for(int j=0;j<n;j++) {
            if(i-c[j]>=0) {
                dp[i] += dp[i-c[j]];
                dp[i] %= mod;
            }
        }
    }
    cout<<dp[x];
}

