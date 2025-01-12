// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int u, vector<int>& vis, stack<int>& st) {
    if(vis[u]==2) return;
    if(vis[u]==1) {
        st.push(-1);
        return;
    }
    vis[u] = 1;
    for(auto v: adj[u]) {
        dfs(adj, v, vis, st);
    }
    st.push(u);
    vis[u] = 2;
}
int main() {
    int n,m,k;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(adj, i, vis, st);
        }
    }
   vector<int> topOrder;
   bool isPossible = true;
   while(!st.empty()) {
       if(st.top()==-1) {
           isPossible = false;
           break;
       }
       topOrder.push_back(st.top());
       st.pop();
   }
   if(isPossible) {
   for(int i:topOrder) {
       cout<<i<<" ";
   }
   } else {
       cout<<"IMPOSSIBLE";
   }
}
