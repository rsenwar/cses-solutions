#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> ar;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        ar.push_back(num);
    }
    
    vector<int> dp;
    dp.push_back(ar[0]);
    for(int i=1;i<n;i++) {
        if(ar[i]>dp.back()) {
            dp.push_back(ar[i]);
        } else {
            int pos = lower_bound(dp.begin(), dp.end(), ar[i]) - dp.begin();
            dp[pos] = ar[i];
        }
    }
    
    cout<<dp.size();
}

