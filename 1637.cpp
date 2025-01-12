#include <bits/stdc++.h>
using namespace std;

vector<int> findDig(int i) {
    vector<int> res;
    while(i) {
        if(i%10 != 0) {
            res.push_back(i%10);
        }
        i /= 10;
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        if(i<=9) {
            dp[i] = 1;
        } else {
            vector<int> dig = findDig(i);
            for(int j=0;j<dig.size();j++) {
                dp[i] = min(dp[i], 1+dp[i-dig[j]]);
            }
        }
    }
    cout<<dp[n];
}

