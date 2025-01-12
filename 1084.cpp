#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> av;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        pq.push(num);
    }
    
    for(int i=0;i<m;i++) {
        int num;
        cin>>num;
        av.push_back(num);
    }
    
    sort(av.begin(), av.end());
    int ptr = 0;
    int total = 0;
    
    while(!pq.empty() && ptr<m) {
        int tp = pq.top();
        
        if(av[ptr]>= tp-k && av[ptr]<=tp+k) {
            total++;
            pq.pop();
            ptr++;
        } else if(av[ptr]<tp-k) {
            ptr++;
        } else {
            pq.pop();
        }
    }
    
    cout<<total;
}









