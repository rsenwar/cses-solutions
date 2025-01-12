#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int> c;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        c.push_back(num);
    }
    vector<int>dp(x+1, 1e9);
    dp[0] = 0;
    for(int i=1;i<=x;i++) {
        for(int j=0;j<n;j++) {
            int am = i - c[j];
            if(am>=0) {
                dp[i] = min(1 + dp[am], dp[i]);
            }
        }
    }
    if(dp[x]>=(int)1e9)  cout<<-1; else cout<<dp[x];
}

