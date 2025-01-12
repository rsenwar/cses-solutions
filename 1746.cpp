#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    set<int> st;
    int pos = 0;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        if(num==0) {
            pos++;
            continue;
        }
        st.insert(num);
        if(num+1<=m) {
            st.insert(num+1);
        }
        if(num-1>=1) {
            st.insert(num-1);
        }
    }
    int mod = 1e9+7;
    int can = st.size();
    long total = can;
    for(int i=1;i<pos;i++) {
        total = (total*can)%mod;
    }
    cout<<(int)total;
    
}