#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    set<int> st;
    
    cin>>n;
    while(n--) {
        int num;
        cin>>num;
        st.insert(num);
    }
    
    cout<<st.size();
}