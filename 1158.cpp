// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int> c;
    vector<int> p;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        c.push_back(num);
    }
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        p.push_back(num);
    }
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    for(int i=0;i<x+1;i++) {
        if(c[0]<=i)
            dp[0][i] = p[0];
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<x+1;j++) {
            dp[i][j] = dp[i-1][j];
            if(j>=c[i]) {
                dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j-c[i]]);
            }
        }
    }
    cout<<dp[n-1][x];
}