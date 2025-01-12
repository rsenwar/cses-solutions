#include <bits/stdc++.h>
using namespace std;
vector<int> route;
void dfs(vector<vector<int>>& adj, vector<int>& vis, int u, int par, vector<int>& p) {
    if(vis[u]==2) {
        return;
    }
    if(vis[u]==1 && route.size()==0) {
        route.push_back(u);
        for(int i=par;i!=u;i=p[i]) {
            route.push_back(i);
        }
        route.push_back(u);
        return;
    }
    if(vis[u]==1) {
        return;
    }
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(v!=par) {
            p[v] = u;
            dfs(adj, vis, v, u, p);
        }
    }
    vis[u] = 2;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj = vector<vector<int>>(n+1, vector<int>{});
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n+1, -1);
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(vis[i]==0) {
            dfs(adj, vis, i, -1, p);
        }
    }
    if(route.size()==0) {
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        cout<<route.size()<<endl;
        for(int i=route.size()-1;i>=0;i--) {
            cout<<route[i]<<" ";
        }
    }
   
}