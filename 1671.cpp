#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,long long>> adj[n+1];
    for(int i=0;i<m;i++) {
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
    }
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, 1});
    vector<int> vis(n+1, 0);
    vector<long long> dist(n+1, LLONG_MAX);
    dist[1] = 0;

    while(!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        int u = tp.second;
        if(tp.first>dist[u]) continue;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v, w]: adj[u]) {
           if(dist[v]>dist[u] + w) {
               dist[v] = dist[u] + w;
               pq.push({dist[v], v});
           } 
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }
    
    
}