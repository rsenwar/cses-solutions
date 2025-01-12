// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int>> adj[n+1];
    vector<tuple<int,int>> rAdj[n+1];
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        rAdj[v].push_back({u,w});
    }
    
    priority_queue<tuple<long long,int>, vector<tuple<long long,int>>, greater<tuple<long long,int>>> pq;
    pq.push({0, 1});
    vector<long long> distOne(n+1, LLONG_MAX);
    distOne[1] = 0;
    long long totalCost = LLONG_MAX;
    while(!pq.empty()) {
        auto [ts, u] = pq.top();
        pq.pop();
        if(distOne[u]<ts) continue;
        for(auto [v, wt]: adj[u]) {
            if(wt+ts < distOne[v]) {
                distOne[v] = ts+wt;
                pq.push({ts+wt, v});
            }
        }
    }
    
   
    vector<long long> distN(n+1, LLONG_MAX);
    distN[n] = 0;
    pq = priority_queue<tuple<long long,int>, vector<tuple<long long,int>>, greater<tuple<long long,int>>>();
    pq.push({0, n});
    while(!pq.empty()) {
        auto [ts, u] = pq.top();
        pq.pop();
        if(distN[u]<ts) continue;
        for(auto [v, wt]: rAdj[u]) {
            if(wt+ts < distN[v]) {
                pq.push({ts+wt, v});
                distN[v] = ts+wt;
            }
        }
    }
    
    for(int i=1;i<=n;i++) {
        for(auto [v, wt]: adj[i]) {
            if(distOne[i]==LLONG_MAX || distN[v]==LLONG_MAX) continue;
            totalCost = min(totalCost, distOne[i] + distN[v] + wt/2);
        }
    }
    
    cout<<totalCost;
}







