#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int> p;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        p.push_back(num);
    }
    
    sort(p.begin(), p.end());
    int l = 0, r = n-1;
    int total = 0;
    
    while(l<=r) {
        if(p[l]+p[r]>x) {
            total++;
            r--;
        } else {
            l++;
            r--;
            total++;
        }
    }
    
    cout<<total;
}

