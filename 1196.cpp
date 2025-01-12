// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> adj[n+1];
    vector<int> shortest;
    
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
   
   priority_queue<tuple<long long,int>, vector<tuple<long long,int>>, greater<tuple<long long,int>>> pq;
   priority_queue<long long> best[n+1];
   
   pq.push({0, 1});
   best[1].push(0);
   while(!pq.empty()) {
       auto [cost, u] = pq.top();
       pq.pop();
       if(cost>best[u].top()) continue;
       
       for(auto& [v, wt]: adj[u]) {
           long long newCost = cost + wt;
           if(best[v].size()<k) {
               best[v].push(newCost);
               pq.push({newCost, v});
           } else if(newCost < best[v].top()) {
               best[v].pop();
               best[v].push(newCost);
               pq.push({newCost, v});
           }
       }
   }
   vector<long long> ans;
   while(!best[n].empty()) {
       ans.push_back(best[n].top());
       best[n].pop();
   }
   for(int i=ans.size()-1;i>=0;i--) {
       cout<<ans[i]<<" ";
   }
}