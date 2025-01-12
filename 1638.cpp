#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int mod = 1e9+7;
    vector<vector<int>>dp(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            char ch;
            cin>>ch;
            if(ch=='*') {
                dp[i][j] = -1;
            } else {
                if(i==0 && j==0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    }
    if(dp[0][0]==-1 || dp[n-1][n-1]==-1) {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(dp[i][j]==-1) {
                continue;
            }
            if(i-1>=0 && dp[i-1][j]!=-1) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            if(j-1>=0 && dp[i][j-1]!=-1) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    cout<<dp[n-1][n-1];
}
